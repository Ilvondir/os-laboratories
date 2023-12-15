#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ex18.c\n\n");

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
        write(pdesk[1], "Komunikat2", 11);
    }

    pid_t third_pid = fork();

    if (third_pid == 0) { // proces 3. dziecko
        char text[50];

        read(pdesk[0], text, 50);

        printf("Odczytano: %s\n", text);
    }

    return 0;
}


// gcc ex18.c -o ex18 -Wall