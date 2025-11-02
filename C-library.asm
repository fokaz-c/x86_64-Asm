global main
extern puts

section .text

main:
    lea     rdi, [rel message]
    call    puts
    ret

message:
    db      "Hello from C-library", 0

