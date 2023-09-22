global long_mode_start
extern kernel_main

section .text
bits 64

long_mode_start:
    mov ax, 0x0
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    call kernel_main
    hlt