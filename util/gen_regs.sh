#!/bin/bash
set -e

if [ $# -ne 2 ]; then
  echo "Usage: $0 <input_pdf> <output_dir>"
  echo ""
  echo "This script will:"
  echo "  1. Extract all register sections from the PDF"
  echo "  2. Generate C header files for each section"
  echo ""
  echo "Example: $0 imx6-reference-manual.pdf imx6_headers"
  exit 1
fi

INPUT_PDF="$1"
OUTPUT_DIR="$2"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SECTIONS_DIR="${OUTPUT_DIR}/sections"
HEADERS_DIR="${OUTPUT_DIR}/headers"

echo "=== i.MX6 Register Header Generator ==="
echo ""
echo "Input PDF: $INPUT_PDF"
echo "Output directory: $OUTPUT_DIR"
echo ""

# Step 1: Extract sections
echo "Step 1: Extracting register sections..."
mkdir -p "$SECTIONS_DIR"
python3 "${SCRIPT_DIR}/page_extract.py" "$INPUT_PDF" "$SECTIONS_DIR"

echo ""
echo "Step 2: Generating header files..."
mkdir -p "$HEADERS_DIR"

# Process each extracted PDF section
for pdf in "$SECTIONS_DIR"/*.pdf; do
  if [ -f "$pdf" ]; then
    basename=$(basename "$pdf" .pdf)
    header="${HEADERS_DIR}/${basename}.h"
    echo "  Processing $basename..."
    python3 "${SCRIPT_DIR}/parse_reg.py" "$pdf" >"$header"
  fi
done

echo ""
echo "=== Done! ==="
echo ""
echo "Generated headers in: $HEADERS_DIR"
ls -lh "$HEADERS_DIR"/*.h 2>/dev/null || echo "No headers generated"
