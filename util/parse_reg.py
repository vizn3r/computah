#!/usr/bin/env python3
import re
import sys

def parse_register_block(lines, start_idx):
    """Parse a single register block starting at start_idx. Returns (end_idx, result) or (end_idx, None)"""
    
    # Find offset/register name line
    reg_match = None
    i = start_idx
    while i < len(lines):
        reg_match = re.search(r'Offset:\s*(\S+)\s+Register Name:\s*(\S+)', lines[i])
        if reg_match:
            break
        i += 1
    
    if not reg_match:
        return len(lines), None
    
    offset = reg_match.group(1)
    reg_name = reg_match.group(2)
    
    # Parse bit fields until we hit another "Offset:" line or end
    fields = []
    i += 1
    while i < len(lines):
        line = lines[i]
        
        # Stop if we hit another register definition
        if re.search(r'Offset:\s*\S+\s+Register Name:', line):
            break
        
        # Try to match bit position with field name on same line first
        bit_match_inline = re.match(r'^\s*(\d+)(?::(\d+))?\s+([RW/-]+)\s+(0x[0-9a-fA-F]+|\d+)\s+([A-Z_][A-Z0-9_]*)', line)
        if bit_match_inline:
            bit_high = int(bit_match_inline.group(1))
            bit_low = int(bit_match_inline.group(2)) if bit_match_inline.group(2) else bit_high
            rw_type = bit_match_inline.group(3)
            field_name = bit_match_inline.group(5)
            
            if rw_type not in ['-', '/']:
                fields.append((bit_high, bit_low, field_name))
            i += 1
            continue
        
        # Otherwise try field name on next line
        bit_match = re.match(r'^\s*(\d+)(?::(\d+))?\s+([RW/-]+)\s+[\dxX-]+\s*$', line)
        if bit_match:
            bit_high = int(bit_match.group(1))
            bit_low = int(bit_match.group(2)) if bit_match.group(2) else bit_high
            rw_type = bit_match.group(3)
            
            # Skip if reserved
            if rw_type in ['-', '/']:
                i += 1
                continue
            
            # Field name should be on next line
            if i + 1 < len(lines):
                next_line = lines[i + 1].strip()
                # Extract field name - should be uppercase with underscores
                field_match = re.match(r'^([A-Z_][A-Z0-9_]*)', next_line)
                if field_match:
                    field_name = field_match.group(1)
                    fields.append((bit_high, bit_low, field_name))
        
        i += 1
    
    return i, (offset, reg_name, fields)

def generate_defines(offset, reg_name, fields):
    output = []
    output.append(f"// {reg_name}")
    output.append(f"#define {reg_name} {offset}")
    
    for bit_high, bit_low, field_name in sorted(fields, key=lambda x: x[0], reverse=True):
        if bit_high == bit_low:
            # Single bit
            define_name = f"{reg_name}_{field_name}"
            output.append(f"#define {define_name} {bit_high}")
        else:
            # Range - output high and low
            output.append(f"#define {reg_name}_{field_name}_HIGH {bit_high}")
            output.append(f"#define {reg_name}_{field_name}_LOW {bit_low}")
    
    return '\n'.join(output)

def main():
    input_text = sys.stdin.read()
    lines = input_text.split('\n')
    
    i = 0
    results = []
    while i < len(lines):
        i, result = parse_register_block(lines, i)
        if result:
            results.append(result)
    
    if not results:
        print("Failed to parse any register definitions", file=sys.stderr)
        sys.exit(1)
    
    for offset, reg_name, fields in results:
        print(generate_defines(offset, reg_name, fields))
        print()

if __name__ == '__main__':
    main()
