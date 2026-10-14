# CHIP-8 Emulator

A CHIP-8 emulator written in C++ for Linux, following [Austin Morlan's CHIP-8 emulator tutorial](https://austinmorlan.com/posts/chip8_emulator/).

## Motivation

I was once told "If you want to understand a system, then build it yourself."

I built this project to better understand how computers execute programs beneath the abstractions we use every day. Rather than treating software as something that simply runs, I wanted to explore how instructions are fetched, decoded, and executed, how memory and processor state are managed, and how software interacts with input and graphical output.

CHIP-8 provided a manageable starting point for exploring these concepts by implementing a virtual machine from the ground up.

## What I Learned

- **Instruction Execution:** Implemented the fetch-decode-execute cycle and a table-driven opcode dispatch system using C++ member-function pointers to map CHIP-8 instructions (35 total) to their respective handlers.
- **Memory Management:** Organized the virtual machine's memory and registers with deterministic, fixed-size allocations, and implemented stack operations for subroutine calls and returns.
- **Bitwise Operations:** Used bit shifting, masking, and other bitwise operations to decode instructions, manipulate register values, and implement opcode behavior.
- **Processor State:** Worked with registers, the program counter, the stack pointer, and timers to manage the state of the virtual machine as instructions execute.
- **Input Handling:** Implemented a 16-key hexadecimal keypad and mapped keyboard input to CHIP-8 key states.
- **Graphics and Timing:** Implemented pixel-based graphics, display updates, and refresh timing to reproduce the behavior expected by CHIP-8 programs.
- **ROM Loading:** Loaded CHIP-8 ROMs into virtual memory and executed their instructions through the emulation loop.

## Technologies

- C++
- Linux
- SDL2
- CMake

## Acknowledgements

This project was built while following Austin Morlan's [Guide to Making a CHIP-8 Emulator](https://austinmorlan.com/posts/chip8_emulator/), which provided the foundation for exploring emulation and computer architecture through hands-on implementation.
