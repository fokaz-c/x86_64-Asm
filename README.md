# x86-64 Assembly Learning

A personal journey into learning x86-64 assembly from scratch using the NASM syntax.

-----

## Table of Contents

  - [About The Project](https://www.google.com/search?q=%23about-the-project)
  - [Prerequisites](https://www.google.com/search?q=%23prerequisites)
  - [Getting Started](https://www.google.com/search?q=%23getting-started)
  - [Project Structure](https://www.google.com/search?q=%23project-structure)

-----

## About The Project

This repository contains a collection of simple x86-64 assembly programs and helper macros. The primary goal is to understand low-level programming concepts, system calls, and the fundamentals of how a computer executes code. All examples are written using the **NASM (Netwide Assembler)** syntax.

-----

## Prerequisites

Before you can assemble and run the code, you'll need to install the necessary tools for your operating system.

### Linux

You need the **NASM Assembler** and **GCC** (to act as the linker).

  - **On Debian/Ubuntu-based systems:**
    ```bash
    sudo apt update
    sudo apt install nasm gcc
    ```
  - **On Arch-based systems:**
    ```bash
    sudo pacman -Syu nasm gcc
    ```

### Windows

You need **NASM** and the **MinGW-w64** toolchain (which includes the GCC linker). The easiest way to install these is with the Chocolatey package manager.

1.  Open PowerShell as an Administrator.
2.  Run the following commands:
    ```powershell
    choco install nasm
    choco install mingw
    ```

-----

## Getting Started

This project includes helper scripts to automate the build process on both Linux and Windows.

### On Linux

Use the `assmbl` shell script to compile and run the code.

  - **Usage:** `assmbl -i <input.asm> [-o <output>] [-r] [-rm]`
  - **Example:** To compile `add.asm`, run it, and clean up the temporary files:
    ```bash
    assmbl -i add.asm -o add -r -rm
    ```

### On Windows

Use the `build-nasm.bat` batch script.

  - **Usage:** `build-nasm.bat <filename_without_extension>`
  - **Example:** To compile `add.asm`:
    ```batch
    build-nasm.bat add
    ```
    This will create an `add.exe` file that you can run.
