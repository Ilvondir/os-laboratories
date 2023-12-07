#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ls.c\n\n");

    printf("Poczatek.\n");

    pid_t pid = fork();

    if (pid == 0) { // dziecie

        execlp("ls", "ls", NULL);

        perror("Blad uruchomienia programu");

        exit(1);
    }
    
    wait(NULL);

    printf("Koniec.\n");

    return 0;
}

/*
    gcc ls.c -o ls -Wall
*/