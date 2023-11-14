    [bits 64]

section .data
str0    db "Enter process id: ", 0
str1    db "%d", 0
str2    db "Success! Process killed!", 0xA, 0
str3    db "Error! There is no process with this id or you dont have permissions to kill it.", 0xA, 0

section .bss
    pid resq 1

section .text
    extern printf
    extern scanf
    global main

main:

    push rbp

    mov rdi, str0       ; str0 moved to rdi as format
    call printf
    
    mov  rdi, str1      ; str1 moved to rdi as format
    mov  rsi, pid       ; adrress pid moved to rsi
    call scanf
    
    pop rbp

    mov rdi, [pid]      ; process id to killed
    mov rsi, 9          ; signal (9: kill)
    mov rax, 62         ; syscall number for kill
    syscall

    cmp rax, 0          ; compare rax with 0

    push rbp

    je success

failure:
    mov rdi, str3       ; str3 moved to rdi as format
    call printf

    jmp exit

success:    
    mov rdi, str2       ; str2 moved to rdi as format
    call printf

exit:
    pop rbp

    mov rax, 60         ; syscall number for exit
    mov rdi, 0          ; returned status
    syscall

; Michal Komsa
;   nasm -felf64 kill.asm
;   gcc -m64 -no-pie -o kill kill.o