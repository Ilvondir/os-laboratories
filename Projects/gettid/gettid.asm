          [bits 32]

section .data
wynik      db "Watek numer %d", 0xA, 0

section .text
          global main
          extern printf
          extern exit

main:
;         esp -> [ret]  ; ret - adres powrotu do asmloader

          mov eax, 224 ; eax = 224 (numer wywolania gettid)
          int 0x80 ; syscall

;         esp -> [ret]

          push eax
;         esp -> [eax][ret]

          push wynik
;         esp -> [wynik][eax][ret]

          call printf  ; printf("Watek numer %d\n", eax);
          add esp, 2*4
;         esp -> [ret]

          push 0
          call exit  ; exit(0)


; Kompilacja:
;   nasm -felf32 gettid.asm
;   gcc -m32 -no-pie -o gettid gettid.o