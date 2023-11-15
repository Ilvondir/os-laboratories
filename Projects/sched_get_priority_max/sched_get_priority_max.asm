    [bits 32]

section .data
zapyt     db "Podaj numer polityki: ", 0
forma     db "%d", 0
sukce     db "Maksymalna wartosc priorytetu dla grupy %d: %d", 0xA, 0
poraz     db "Podano bledny numer polityki.", 0xA, 0

section .text
    global main
    extern printf
    extern scanf
    extern exit

main:

    push zapyt
    call printf

    push esp
    push forma
    call scanf
    add esp, 2*4

    mov eax, 159 ; numer syscalla do wywolania 159 = sched_get_priority_max
    pop ebx ; argument wywolania czyli numer priorytetu
    int 0x80 ; syscall

    cmp eax, -1 ; w eax jest zwrocona wartosc robimy if zeby sprawdzic czy jest poprawna (jesli -1 to blad jeszcze co innego to jest dobrze)
    
    jle zle ; idz do zle jesli mniejsza lub rowna

dobrze:

    push eax
    push ebx
    push sukce

    call printf

    add esp, 3*4

    jmp zakoncz

zle:

    push poraz
    call printf

    add esp, 1*4

zakoncz:
    push 0
    call exit
    
; Z asm na o: nasm -felf32 sched_get_priority_max.asm
; Z o na wykonywalny(to ju¿ na Linuksie): gcc -m32 -no-pie -o sched_get_priority_max sched_get_priority_max.o