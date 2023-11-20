          [bits 32]

section .data
finput    db "Select politic: ", 0
format    db "%d", 0
ferror    db "Error!", 0xA, 0
fpriority db "Min priority: %d", 0xA, 0

section .text
          global main
          extern printf
          extern scanf
          extern exit

main:
;         esp -> [ret]  ; ret - adres powrotu do asmloader

          push finput
;         esp -> [finput][ret]

          call printf  ; printf("Select politic: ");

          push esp
;         esp -> [addr_num][num][ret]

          push format
;         esp -> [format][addr_num][num][ret]

          call scanf  ; scanf("%d", &num);
          
          add esp, 2*4  ; esp = esp + 8
;         esp -> [num][ret]

          mov eax, 160  ; eax = 160
          pop ebx   ; ebx = num
;         esp -> [ret]
          int 0x80  ; syscall
          
          cmp eax, 0  ; eax - 0  ; OF SF ZF AF PF CF affected
          
;         esp -> [ret]
          jl error1  ; jump to error1 if lower

          push eax
;         esp -> [result][ret]

          push fpriority
;         esp -> [fpriority][result][ret]

          call printf  ; printf("Min priority: %d\n", result);
          
          add esp, 2*4  ; esp = esp + 8
;         esp -> [ret]

          jmp exit1  ; jump to exit

error1:
          push ferror
;         esp -> [ferror][ret]

          call printf  ; printf("Error!\n");

          add esp, 1*4  ; esp = esp + 4
;         esp -> [ret]

exit1:
;         esp -> [ret]
          push 0
;         esp -> [0][ret]
          call exit  ; exit(0)

; nasm -f elf32 sched_get_priority_min.asm
; gcc -m32 -no-pie -o sched_get_priority_min sched_get_priority_min.o