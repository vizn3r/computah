cmake_minimum_required(VERSION 3.20)
project(computah ASM C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2 -DNDEBUG -marm -mcpu=cortex-a9 -ffreestanding -nostdlib")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -DDEBUG")

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_SIZE arm-none-eabi-size)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

option(BUILD_TESTS "Build tests" OFF)
option(RUN_QEMU "Run QEMU after build" OFF)
option(UPLOAD_SD "Upload to SD card after build" OFF)

# modules
#include_directories(common)
#add_subdirectory(common)
#add_subdirectory(kernel)
#add_subdirectory(boot)
#add_subdirectory(user)

# bootloader
#add_executable(boot.elf
#  boot/boot.S
#  boot/loader.c
#)
#
#target_link_libraries(boot.elf
#  common
#)
#
#set_target_properties(boot.elf PROPERTIES
#  LINK_FLAGS "-T${CMAKE_CURRENT_SOURCE_DIR}/boot/boot.ld -nostdlib"
#)
#
#add_custom_command(TARGET boot.elf POST_BUILD
#  COMMAND ${CMAKE_OBJCOPY} -O binary boot.elf bootloader.bin
#  COMMENT "Creating bootloader.bin"
#)

# kernel
add_executable(kernel.elf
  kernel/kernel.c
)

set_target_properties(kernel.elf PROPERTIES
  LINK_FLAGS "-T${CMAKE_CURRENT_SOURCE_DIR}/kernel/kernel.ld -nostdlib -nodefaultlibs -nostartfiles"
)

#target_link_libraries(kernel.elf
#  common
#)

#add_custom_command(TARGET kernel.elf POST_BUILD
#  COMMAND ${CMAKE_OBJCOPY} -O binary kernel.elf kernel.bin
#  COMMENT "Creating kernel.bin"
#)

# Unity for tests
#if(TESTS)
#  add_library(unity lib/unity/src/unity.c)
#  target_include_directories(unity PUBLIC lib/unity/src)
#
#  enable_testing()
#
#  file(GLOB TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test/test_*.c")
#  foreach(test_file ${TEST_FILES})
#    get_filename_component(test_name ${test_file} NAME_WE)
#    add_executable(${test_name} ${test_file})
#    target_link_libraries(${test_name} unity)
#    add_test(NAME ${test_name} COMMAND $<TARGET_FILE:${test_name}>)
#  endforeach()
#endif()
