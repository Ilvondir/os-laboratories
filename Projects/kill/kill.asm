          [bits 64]

section .data
str0      db "Enter process id: ", 0
str1      db "%d", 0
str2      db "Success! Process killed!", 0xA, 0
str3      db "Error! There is no process with this id or you dont have permissions to kill it.", 0xA, 0

section .bss
pid       resq 1

section .text
          extern printf
          extern scanf
          global main

main:

;         rsp -> [ret]  ; ret - adres powrotu do asmloader

          push rbp
;         rsp -> [rbp][ret]

          mov rdi, str0  ; str0 moved to rdi as format
          call printf  ; printf("Enter process id: ");

          mov  rdi, str1  ; rdi = &str1
          mov  rsi, pid  ; rsi = &pid
          call scanf  ; scanf("%d", &pid);
          
          pop rbp  ; rbp = rbp
;         rsp -> [ret]
      
          mov rdi, [pid] ; rdi = pid
          mov rsi, 9  ; rsi = 9 (9: SIGKILL)
          mov rax, 62  ; rax = 62 (62: kill)
          syscall  ; kill(pid, 9);

          cmp rax, 0  ; rax - 0               ; OF SF ZF AF PF CF affected
      
          push rbp
;         rsp -> [rbp][ret]
      
          je success  ; jump if equal ; jump if rax == 0               ; jump if ZF = 1

failure:
          mov rdi, str3  ; rdi = &str3
          call printf  ; printf("Error! There is no process with this id or you dont have permissions to kill it.\n");

          jmp exit  ; jump

success:    
          mov rdi, str2  ; rdi = &str3
          call printf  ; printf("Success! Process killed!\n");

exit:
          pop rbp  ; rbp = rbp
;         rsp -> [ret]

          mov rax, 60  ; rax = 60
          mov rdi, 0  ; rdi = 0
          syscall  ; exit(0)

; Michal Komsa
;   nasm -felf64 kill.asm
;   gcc -m64 -no-pie -o kill kill.o