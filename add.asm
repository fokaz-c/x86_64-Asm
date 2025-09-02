%include "macros/io.inc"

section .data
    test_msg db "Hello", 5
    newline db 10, 1
section .text
    global _start

_start:
    mov rax, 100
    mov rbx, 2
    add rax, rbx
    mov r8, rax

    print test_msg, 5
    print newline, 1

    print_num r8
    print newline, 1
    return 0

