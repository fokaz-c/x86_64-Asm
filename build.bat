@echo off
REM Usage: build-nasm.bat <filename_without_extension>
nasm -f win64 %1.asm -o %1.obj
gcc -nostartfiles -no-pie %1.obj -o %1.exe
