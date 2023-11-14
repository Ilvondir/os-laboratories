    [bits 64]

section .data
tekst   db "ID procesu mojego rodzica to: %d", 0xA, 0

section .text
    extern printf
    global main

main:
    
    mov rax, 110  ; numer syscall getppid
    syscall  ; wywolanie syscalla z rejestru rax

    push rbp

    mov rdi, tekst  ; tekst do wyswietlenia
    mov rsi, rax  ; wartosc dla %d z tekstu
    call printf

    pop rbp
    
    mov rax, 60  ; numer syscalla exit
    mov rdi, 0  ; zwracana wartosc
    syscall  ; wywolanie syscalla z rejestru rax


; Kompilacja: nasm -felf64 getppid.asm potem na Linuxie gcc -m64 -no-pie -o getppid getppid.o 