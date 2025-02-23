# CHIP8-emulator
# 🚧 This project is still under development! 🚧
## Overview

This is a CHIP-8 emulator written in C++ using FreeGLUT for display and input handling. The emulator fetches, decodes, and executes CHIP-8 opcodes while rendering graphics and handling user input.

## Features
- CPU Emulation: Implements CHIP-8 instruction set
- Memory Management: Loads and executes CHIP-8 ROMs
- Graphics Rendering: Uses OpenGL and FreeGLUT for display
- Input Handling: Maps PC keyboard to CHIP-8 keypad

## Dependencies
-Ensure you have the following installed:
-C++ Compiler (GCC, Clang, or MSVC)
-CMake (Optional, if using a build system)
-FreeGLUT (For OpenGL rendering)

## Controls

The CHIP-8 uses a hexadecimal keypad. The key mappings are:

```bash
1 2 3 C    -> 1 2 3 4
4 5 6 D    -> Q W E R
7 8 9 E    -> A S D F
A 0 B F    -> Z X C V
```
💡 Note: This emulator is for educational purposes only.
