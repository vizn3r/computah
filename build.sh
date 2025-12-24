#!/bin/bash
set -e

BUILD_TYPE=Release
BUILD=ON # Default to ON for normal build
TESTS=OFF
QEMU=OFF
UPLOAD=OFF
NEW_SD=OFF

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
  -new-sd)
    NEW_SD=ON
    shift
    ;;
  -upload)
    UPLOAD=ON
    shift
    ;;
  *)
    echo "Unknown option: $1"
    echo "Usage: $0 [-debug] [-tests] [-qemu] [-upload] [-new-sd]"
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
  echo " >> Building:"
  cmake --build . -- -j$(nproc)
fi

if [ -f compile_commands.json ]; then
  cp compile_commands.json ..
fi

#if [ "$TESTS" = "ON" ]; then
#  echo " >> Running tests:"
#  ctest -V --output-on-failure
#fi
#
#if [ "$NEW_SD" = "ON" ]; then
#  echo " >> Creating new SD card image:"
#  if [ -f sdcard.img ]; then
#    rm sdcard.img
#  fi
#  dd if=/dev/zero of=sdcard.img bs=1M count=64
#  dd if=../u-boot-sunxi-with-spl.bin of=sdcard.img bs=1024 seek=8 conv=notrunc
#fi
#
#if [ "$UPLOAD" = "ON" ]; then
#  echo " >> Uploading to SD card:"
#  #dd if=bootloader-egon.bin of=sdcard.img bs=1024 seek=40 conv=notrunc
#  dd if=bootloader.bin of=sdcard.img bs=1024 seek=40 conv=notrunc
#  dd if=kernel.bin of=sdcard.img bs=1024 seek=1024 conv=notrunc
#fi

if [ "$QEMU" = "ON" ]; then
  echo " >> Starting QEMU:"
  qemu-system-arm -M sabrelite -kernel kernel.elf -serial stdio
fi
