# x86-64 Assembly Learning

A personal journey into learning x86-64 assembly from scratch using the NASM syntax.

---

## Table of Contents

* [About The Project](#about-the-project)
* [Prerequisites](#prerequisites)
* [Getting Started](#getting-started)
* [Project Structure](#project-structure)

---

## About The Project

This repository contains a collection of simple x86-64 assembly programs and helper macros. The primary goal is to understand low-level programming concepts, system calls, and the fundamentals of how a computer executes code. All examples are written using the **NASM (Netwide Assembler)** syntax.

---

## Prerequisites

Before you can assemble and run the code, you'll need to install the necessary tools for your operating system.

### Linux

You need the **NASM Assembler** and **GCC** (to act as the linker).

* **On Debian/Ubuntu-based systems:**

  ```bash
  sudo apt update
  sudo apt install nasm gcc
  ```

* **On Arch-based systems:**

  ```bash
  sudo pacman -Syu nasm gcc
  ```

### Windows

You need **NASM** and the **MinGW-w64** toolchain (which includes the GCC linker).
The easiest way to install these is with the Chocolatey package manager.

1. Open PowerShell as an Administrator.
2. Run the following commands:

   ```powershell
   choco install nasm
   choco install mingw
   ```

---

## Getting Started

This project includes helper scripts to automate the build process on both Linux and Windows.

### On Linux

Use the `assmbl` shell script to compile and run the code.

#### Basic Usage

```bash
assmbl -i <input.asm> [-o <output>] [-r] [-rm] [-c]
```

#### Options

| Flag  | Description                                                      |
| ----- | ---------------------------------------------------------------- |
| `-i`  | Input file (required)                                            |
| `-o`  | Output filename (default: a.out)                                 |
| `-r`  | Run the program after building                                   |
| `-rm` | Remove generated files after running                             |
| `-c`  | Link against the C standard library (for `puts`, `printf`, etc.) |

#### Examples

* **Simple syscall-based assembly program:**

  ```bash
  assmbl -i hello.asm -o hello -r
  ```

* **Program that uses C library functions:**

  ```bash
  assmbl -i C-library.asm -o C-library -r -c
  ```

  The `-c` flag ensures the program is linked with the standard C library using `gcc -no-pie`.

* **Clean up after running:**

  ```bash
  assmbl -i add.asm -r -rm
  ```

### On Windows

Use the `build-nasm.bat` batch script.

#### Usage

```batch
build-nasm.bat <filename_without_extension>
```

#### Example

```batch
build-nasm.bat add
```

This creates an `add.exe` file you can run directly.

NOTE: I did not update the script for C-library usage (Windows) (sorry)
