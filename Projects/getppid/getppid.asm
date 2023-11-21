          [bits 64]

section .data
tekst     db "ID procesu mojego rodzica to: %d", 0xA, 0

section .text
          extern printf
          global main

main:

;         rsp -> [ret]  ; ret - adres powrotu do asmloader
    
          mov rax, 110  ; rax = 110  ; getppid
          syscall  ; wywolanie syscalla z rejestru rax

          push rbp
;         rsp -> [rbp_stack][ret]

          mov rdi, tekst  ; rdi = &tekst
          mov rsi, rax  ; rsi = &rax
          call printf  ; printf("ID procesu mojego rodzica to: %d\n", rax);

          pop rbp  ; rbp = rbp_stack
;         rsp -> [ret]
    
          mov rax, 60  ; rax = 60  ; exit
          mov rdi, 0  ; rdi = 0
          syscall  ; wywolanie syscalla z rejestru rax  ; exit(0)


;         Kompilacja: nasm -felf64 getppid.asm potem na Linuxie gcc -m64 -no-pie -o getppid getppid.o 