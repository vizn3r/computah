#!/usr/bin/env python3
import sys
import re
import os
import fitz  # PyMuPDF

def find_register_sections(doc):
    """
    Scan through PDF and find all register definition sections.
    Returns list of (section_name, start_page, end_page) tuples.
    """
    sections = []
    current_section = None
    current_start = None
    
    for page_num in range(len(doc)):
        page = doc[page_num]
        text = page.get_text()
        
        # Look for section headers like:
        # "64.15 UART Memory Map/Register Definition"
        # "23.7 GPIO Memory Map/Register Definition"
        # Peripheral name should be 1-3 words, not a huge string of garbage
        header_match = re.search(r'(\d+\.\d+)\s+([A-Z][A-Za-z0-9]+(?:\s+[A-Z][A-Za-z0-9]+){0,2})\s+Memory Map/Register Definition', text)
        
        if header_match:
            # If we were tracking a previous section, save it
            if current_section:
                sections.append((current_section, current_start, page_num - 1))
            
            # Start tracking new section
            section_num = header_match.group(1)
            section_name = header_match.group(2).strip()
            current_section = section_name
            current_start = page_num
            
            print(f"Found section: {section_num} {section_name} (page {page_num})", file=sys.stderr)
        
        # Also check if we've hit a new chapter/section (end of register definitions)
        # Pattern like "Chapter 65" or "64.16" (next subsection)
        if current_section:
            chapter_match = re.search(r'^Chapter \d+|^\d+\.\d+\s+[A-Z]', text)
            if chapter_match and page_num > current_start:
                # Check if this is actually ending the register section
                # (register sections usually end when we see a new major section)
                if 'Memory Map/Register Definition' not in text:
                    # End current section
                    sections.append((current_section, current_start, page_num - 1))
                    current_section = None
                    current_start = None
    
    # Don't forget the last section if we were still tracking one
    if current_section:
        sections.append((current_section, current_start, len(doc) - 1))
    
    return sections

def extract_section(doc, section_name, start_page, end_page, output_dir):
    """Extract pages from start_page to end_page and save as separate PDF"""
    
    # Clean up section name for filename
    filename = section_name.lower().replace(' ', '_').replace('/', '_')
    filename = re.sub(r'[^a-z0-9_]', '', filename)
    output_path = os.path.join(output_dir, f"{filename}.pdf")
    
    # Create new PDF with just these pages
    new_doc = fitz.open()
    for page_num in range(start_page, end_page + 1):
        new_doc.insert_pdf(doc, from_page=page_num, to_page=page_num)
    
    new_doc.save(output_path)
    new_doc.close()
    
    num_pages = end_page - start_page + 1
    print(f"Extracted {section_name}: pages {start_page}-{end_page} ({num_pages} pages) -> {output_path}", file=sys.stderr)
    
    return output_path

def main():
    if len(sys.argv) != 3:
        print("Usage: extract_register_sections.py <input_pdf> <output_dir>")
        sys.exit(1)
    
    input_pdf = sys.argv[1]
    output_dir = sys.argv[2]
    
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    try:
        doc = fitz.open(input_pdf)
    except Exception as e:
        print(f"Error opening PDF: {e}")
        sys.exit(1)
    
    print(f"Scanning {len(doc)} pages for register sections...", file=sys.stderr)
    
    sections = find_register_sections(doc)
    
    if not sections:
        print("No register sections found!", file=sys.stderr)
        sys.exit(1)
    
    print(f"\nFound {len(sections)} register sections:", file=sys.stderr)
    for name, start, end in sections:
        print(f"  - {name}: pages {start}-{end}", file=sys.stderr)
    
    print(f"\nExtracting sections to {output_dir}...", file=sys.stderr)
    
    extracted_files = []
    for section_name, start_page, end_page in sections:
        output_path = extract_section(doc, section_name, start_page, end_page, output_dir)
        extracted_files.append(output_path)
    
    doc.close()
    
    print(f"\nDone! Extracted {len(extracted_files)} sections.", file=sys.stderr)
    print("\nTo generate headers, run:", file=sys.stderr)
    print(f"  mkdir -p headers", file=sys.stderr)
    print(f"  for pdf in {output_dir}/*.pdf; do", file=sys.stderr)
    print(f"    python3 parse_imx6_registers.py \"$pdf\" > headers/$(basename \"$pdf\" .pdf).h", file=sys.stderr)
    print(f"  done", file=sys.stderr)

if __name__ == '__main__':
    main()
