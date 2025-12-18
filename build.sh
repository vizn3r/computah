#!/bin/bash
set -e

BUILD_TYPE=Release
BUILD=ON # Default to ON for normal build
TESTS=OFF
QEMU=OFF
UPLOAD=OFF

# If any args are passed, turn off normal build unless explicitly enabled
if [ $# -gt 0 ]; then
  BUILD=OFF
fi

while [[ $# -gt 0 ]]; do
  case $1 in
  -debug)
    BUILD_TYPE=Debug
    BUILD=ON
    UPLOAD=ON
    QEMU=ON
    shift
    ;;
  -tests)
    TESTS=ON
    shift
    ;;
  -qemu)
    QEMU=ON
    shift
    ;;
  -upload)
    UPLOAD=ON
    shift
    ;;
  *)
    echo "Unknown option: $1"
    echo "Usage: $0 [-debug] [-tests] [-qemu] [-upload]"
    exit 1
    ;;
  esac
done

mkdir -p build
cd build

cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DTESTS=$TESTS \
  ..

if [ "$BUILD" = "ON" ]; then
  cmake --build . -- -j$(nproc)
fi

if [ -f compile_commands.json ]; then
  cp compile_commands.json ..
fi

if [ "$TESTS" = "ON" ]; then
  ctest -V --output-on-failure
fi

if [ "$UPLOAD" = "ON" ]; then
  dd if=bootloader.bin of=../sdcard.img bs=1024 seek=40 conv=notrunc
  dd if=kernel.bin of=../sdcard.img bs=1024 seek=1024 conv=notrunc
fi

if [ "$QEMU" = "ON" ]; then
  qemu-system-arm -M orangepi-pc -drive file=../sdcard.img,format=raw,if=sd -serial stdio
fi
