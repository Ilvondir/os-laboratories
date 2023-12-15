#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ex17.c\n\n");

    int pdesk[2];

    if (pipe(pdesk) == -1) {
        perror("Error with pipe: ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) { // proces 1. dziecko
        write(pdesk[1], "Komunikat", 10);
    }

    pid_t second_pid = fork();

    if (second_pid == 0) { // proces 2. dziecko
        char buf[10];

        read(pdesk[0], buf, 10);

        printf("Odczytano: %s\n", buf);
    }

    return 0;
}


// gcc ex17.c -o ex17 -Wall