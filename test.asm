.global _start
.intel_syntax noprefix

_start:

    // write
    mov rax, 1
    mov rdi, 0
    lea rsi, [hello_world]
    mov rdx, 13
    syscall

    // read and write
    mov rax, 0
    mov rdi, 0
    lea rsi, [buffer]
    mov rdx, 5
    syscall

    // write
    mov rax, 1
    mov rdi, 0
    lea rsi, [buffer]
    mov rdx, 5
    syscall

    // exit
    mov rax, 60
    mov rdi, 0
    syscall 

hello_world:
    .asciz "Hello, World!\n"

buffer:
    .space 5
