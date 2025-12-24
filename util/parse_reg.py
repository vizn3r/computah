#!/usr/bin/env python3
import sys
import re
import fitz  # PyMuPDF

def extract_memory_map(doc):
    """Extract base addresses and register offsets from memory map table"""
    bases = {}
    registers = {}
    peripheral_name = None
    
    # Look through first few pages for memory map table
    has_underscore_addrs = False
    
    # First pass: detect address format
    for page_num in range(min(5, len(doc))):
        page = doc[page_num]
        text = page.get_text()
        if re.search(r'\b[0-9A-F]{2,3}_[0-9A-F]{4}\b', text):
            has_underscore_addrs = True
            break
    
    for page_num in range(min(5, len(doc))):
        page = doc[page_num]
        text = page.get_text()
        lines = text.split('\n')
        
        # In the table, address and register name are on separate lines
        # Format:
        # 202_0000
        # UART Receiver Register (UART1_URXD)
        # Or:
        # 11_0000
        # AHB to APBH Bridge Control Register (APBH_CTRL0)
        # Or (single instance):
        # 0
        # Register ID Low 16 bits (PCIE_PHY_IDCODE_LO)
        for i in range(len(lines) - 1):
            addr_match = None
            
            if has_underscore_addrs:
                # ONLY match underscore format
                addr_match = re.match(r'^([0-9A-F]{2,3}_[0-9A-F]{4})$', lines[i].strip())
            else:
                # No underscores seen - accept bare hex
                bare_hex = re.match(r'^([0-9A-F]{1,4})$', lines[i].strip())
                if bare_hex and i+1 < len(lines):
                    # Verify next line has register name
                    next_text = ' '.join(lines[i+1:min(i+4, len(lines))])
                    if re.search(r'\([A-Z][A-Z0-9_]+\)', next_text):
                        addr_match = bare_hex
            
            if addr_match:
                # Next line(s) should have register name - check next 3 lines
                reg_text = ' '.join(lines[i+1:min(i+4, len(lines))])
                
                # Try multi-instance pattern first (UART1_URXD, GPIO1_DR)
                reg_match = re.search(r'\(([A-Z][A-Z0-9]*)(\d+)_(\w+)\)', reg_text)
                if reg_match:
                    addr_str = addr_match.group(1).replace('_', '')
                    periph_prefix = reg_match.group(1)  # UART, GPIO, etc.
                    instance_num = reg_match.group(2)
                    reg_name = reg_match.group(3)
                    
                    if peripheral_name is None:
                        peripheral_name = periph_prefix
                    
                    addr = int(addr_str, 16)
                    
                    # Store base address for this instance
                    base_key = f'{periph_prefix}{instance_num}'
                    if base_key not in bases:
                        bases[base_key] = addr
                    
                    # Calculate offset from base
                    offset = addr - bases[base_key]
                    
                    # Store register offset (without instance number)
                    if reg_name not in registers:
                        registers[reg_name] = offset
                else:
                    # Try single-instance pattern (APBH_CTRL0, CSI2IPU_SW_RST)
                    single_match = re.search(r'\(([A-Z][A-Z0-9]*)_(\w+)\)', reg_text)
                    if single_match:
                        addr_str = addr_match.group(1).replace('_', '')
                        periph_prefix = single_match.group(1)
                        reg_name = single_match.group(2)
                        
                        if peripheral_name is None:
                            peripheral_name = periph_prefix
                        
                        addr = int(addr_str, 16)
                        
                        # Single instance - store base address on first occurrence
                        base_key = periph_prefix
                        if base_key not in bases:
                            bases[base_key] = addr  # First register becomes base
                        
                        # Calculate offset from base
                        offset = addr - bases[base_key]
                        
                        # Store register offset
                        if reg_name not in registers:
                            registers[reg_name] = offset
    
    return peripheral_name, bases, registers

def extract_bit_fields(doc, peripheral_name):
    """Extract bit field definitions from register detail pages"""
    bit_fields = {}
    
    for page_num in range(len(doc)):
        page = doc[page_num]
        text = page.get_text()
        
        # Look for register definition headers like "64.15.1 UART Receiver Register (UARTx_URXD)"
        # Make it generic: "X.Y.Z <Periph> ... Register (<Periph>x_<REG>)"
        reg_match = re.search(rf'{peripheral_name}.*Register \({peripheral_name}x?_(\w+)\)', text)
        if not reg_match:
            continue
            
        reg_name = reg_match.group(1)
        
        # Find the "field descriptions" section
        lines = text.split('\n')
        
        # Find where field descriptions start
        in_field_desc = False
        fields = {}  # Use dict to avoid duplicates: bit_pos -> field_name
        
        for i in range(len(lines)):
            line = lines[i].strip()
            
            # Look for "field descriptions" header
            if 'field descriptions' in line.lower():
                in_field_desc = True
                continue
            
            if not in_field_desc:
                continue
            
            # Stop at next section or page end
            if line.startswith('64.15.') and 'field descriptions' not in line.lower():
                break
            
            # Match bit range patterns: "31-16" or "15" or "7–6" (different dash chars)
            bit_match = re.match(r'^(\d+)[–\-](\d+)$|^(\d+)$', line)
            if bit_match:
                # Next non-empty line should be the field name
                # Field names should be valid C identifiers (uppercase preferred)
                field_name = None
                for j in range(i+1, min(i+5, len(lines))):
                    potential_name = lines[j].strip()
                    if not potential_name:
                        continue
                    
                    # Field name should be all caps, underscores, and maybe numbers
                    # And not a common keyword
                    # Also: if it's a single digit (0 or 1), it's a value description, not a field name
                    if re.match(r'^[A-Z][A-Z0-9_]*$', potential_name):
                        # Exclude common header/table words and document metadata
                        excluded = ['FIELD', 'DESCRIPTION', 'RESERVED', 'TABLE', 
                                   'CONTINUES', 'PAGE', 'NEXT', 'SECTION',
                                   'BCH', 'REVISION', 'HISTORY', 'REFERENCE',
                                   'FREESCALE', 'SEMICONDUCTOR', 'INC', 'MANUAL',
                                   'PROCESSOR', 'APPLICATIONS', 'COPYRIGHT']
                        if potential_name not in excluded:
                            field_name = potential_name
                            break
                
                if not field_name:
                    continue
                
                if bit_match.group(3):  # Single bit
                    bit_high = bit_low = int(bit_match.group(3))
                else:  # Bit range
                    bit_high = int(bit_match.group(1))
                    bit_low = int(bit_match.group(2))
                
                # Use bit position as key to avoid duplicates
                key = (bit_high, bit_low)
                if key not in fields:
                    fields[key] = field_name
        
        if fields:
            # Convert back to list
            bit_fields[reg_name] = [(h, l, n) for (h, l), n in fields.items()]
    
    return bit_fields

def generate_header(peripheral_name, bases, registers, bit_fields):
    """Generate C header file content"""
    output = []
    
    output.append("//")
    output.append(f"// i.MX6 {peripheral_name} Register Definitions")
    output.append("// Auto-generated from reference manual")
    output.append("//")
    output.append("")
    output.append("#pragma once")
    output.append("")
    
    # Check if single instance or multi-instance
    is_single_instance = len(bases) == 1 and peripheral_name in bases
    
    # Generate base addresses
    output.append(f"// {peripheral_name} Base Addresses")
    if is_single_instance:
        # Single instance peripheral
        output.append(f"#define {peripheral_name}_BASE 0x{bases[peripheral_name]:08X}")
    else:
        # Multi-instance peripheral
        def get_instance_num(name):
            match = re.search(r'\d+', name)
            return int(match.group()) if match else 0
        
        for instance_name in sorted(bases.keys(), key=get_instance_num):
            output.append(f"#define {instance_name}_BASE 0x{bases[instance_name]:08X}")
    output.append("")
    
    # Generate accessor macros
    output.append(f"// {peripheral_name} Accessor Macros")
    if is_single_instance:
        output.append(f"#define {peripheral_name}(reg) *(volatile unsigned int*)({peripheral_name}_BASE + (reg))")
    else:
        def get_instance_num(name):
            match = re.search(r'\d+', name)
            return int(match.group()) if match else 0
        
        for instance_name in sorted(bases.keys(), key=get_instance_num):
            output.append(f"#define {instance_name}(reg) *(volatile unsigned int*)({instance_name}_BASE + (reg))")
    output.append("")
    
    # Generate register offsets
    output.append(f"// {peripheral_name} Register Offsets")
    for reg_name in sorted(registers.keys()):
        output.append(f"#define {peripheral_name}_{reg_name} 0x{registers[reg_name]:04X}")
    output.append("")
    
    # Generate bit field definitions
    for reg_name in sorted(bit_fields.keys()):
        output.append(f"// {peripheral_name}_{reg_name}")
        fields = bit_fields[reg_name]
        
        for bit_high, bit_low, field_name in sorted(fields, key=lambda x: x[0], reverse=True):
            if bit_high == bit_low:
                # Single bit
                output.append(f"#define {peripheral_name}_{reg_name}_{field_name} {bit_high}")
            else:
                # Bit range
                output.append(f"#define {peripheral_name}_{reg_name}_{field_name}_HIGH {bit_high}")
                output.append(f"#define {peripheral_name}_{reg_name}_{field_name}_LOW {bit_low}")
        output.append("")
    
    return '\n'.join(output)

def main():
    if len(sys.argv) != 2:
        print("Usage: parse_imx6_registers.py <pdf_file>")
        sys.exit(1)
    
    pdf_path = sys.argv[1]
    
    try:
        doc = fitz.open(pdf_path)
    except Exception as e:
        print(f"Error opening PDF: {e}")
        sys.exit(1)
    
    # Extract data from PDF
    peripheral_name, bases, registers = extract_memory_map(doc)
    
    if not peripheral_name:
        print("Error: Could not detect peripheral name from PDF", file=sys.stderr)
        sys.exit(1)
    
    bit_fields = extract_bit_fields(doc, peripheral_name)
    
    # Generate output
    header = generate_header(peripheral_name, bases, registers, bit_fields)
    print(header)
    
    doc.close()

if __name__ == '__main__':
    main()
