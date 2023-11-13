    [bits 32]

section .data
wynik   db "Watek numer %d", 0xA, 0

section .text
    global main
    extern printf
    extern exit
 
main:
    
    mov eax, 224 ; 224 to numer wywolania gettid
    int 0x80 ; syscall

    push eax

    push wynik
    call printf
    add esp, 2*4

    push 0
    call exit


; Kompilacja:
;   nasm -felf32 gettid.asm
;   gcc -m32 -no-pie -o gettid gettid.o