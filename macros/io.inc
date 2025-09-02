; @file  io.inc
; @brief  Macros library for I/O operations
; @author fokaz-c

%include "macros/math.inc"

; Print data to stdout
; @param %1 - buffer address
; @param %2 - number of bytes to print
%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

; Print integer as decimal string
; @param %1 - integer value to print
%macro print_num 1
    mov rax, %1         ; The number to print
    mov rcx, 10         ; The divisor
    mov r8, rsp         ; Save the stack pointer to calculate length later

    ; Conversion loop
.conversion_loop:
    xor rdx, rdx        ; Clear rdx for division
    div rcx             ; rax = rax / 10, rdx = remainder
    add dl, '0'         ; Convert remainder to ASCII character
    dec rsp             ; Make space on the stack for the character
    mov [rsp], dl       ; Move the character onto the stack
    test rax, rax       ; Is the quotient zero?
    jnz .conversion_loop  ; If not, loop again

    ; Now, print the string we built on the stack
    mov rdx, r8         ; rdx = original stack pointer
    sub rdx, rsp        ; rdx = length (original_sp - current_sp)
    print rsp, rdx      ; Call your existing print macro!

    mov rsp, r8         ; Restore the stack pointer
%endmacro

; Read line from stdin, strip newline, and null-terminate
; @param %1 - buffer address
; @param %2 - maximum bytes to read
; @return rax - number of characters in final string (excluding null terminator)
%macro read_line 2
    push rdi
    push rsi
    push rdx

    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, %2
    syscall

    cmp rax, 0
    je %%done

    dec rax
    cmp byte [%1 + rax], 0x0A
    jne %%add_null

    mov byte [%1 + rax], 0x00
    jmp %%done

%%add_null:
    inc rax
    mov byte [%1 + rax], 0x00
    dec rax

%%done:
    pop rdx
    pop rsi
    pop rdi
%endmacro

; Exit program with specified exit code
; @param %1 - exit code
%macro return 1
    mov rax, 60
    mov rdi, %1
    syscall
%endmacro
