; @file math.inc
; @brief Macros for arithmetic operations
; @author fokaz-c
;
; Provides reusable macros for basic arithmetic.
; Use with `%include "macros/math.inc"` in your .asm file.

; Get the modulus of given inputs
; @param %1 - destination address of the modulus operation
; @param %2 - dividend
; @param %3 - divisor
%macro mod 3
    mov rax, %2
    cqo
    idiv %3
    mov %1, rdx
%endmacro

; Find minimum of two values
; @param %1 - destination (defaults to rax if not specified)
; @param %2 - first value to compare
; @param %3 - second value to compare
%macro min 2-3 rax
   mov rax, %2
   cmp rax, %3
   jle %%store_first
   mov %1, %3
   jmp %%done
%%store_first:
   mov %1, %2
%%done:
%endmacro

; Find maximum of two values
; @param %1 - destination (defaults to rax if not specified)
; @param %2 - first value to compare
; @param %3 - second value to compare
%macro max 2-3 rax
   mov rax, %2
   cmp rax, %3
   jge %%store_first
   mov %1, %3
   jmp %%done
%%store_first:
   mov %1, %2
%%done:
%endmacro
