#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("pipe.c\n\n");
    
    int pdesk[2];

    if (pipe(pdesk) == -1) {
        perror("Blad tworzenia potoku");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Blad tworzenia procesu potomnego");
        exit(1);
    }

    if (pid == 0) {
        if (write(pdesk[1], "Hallo!", 7) == -1) {
            perror("Blad zapisu do potoku");
            exit(1);
        }

        exit(0);
    }

    if (pid > 0) {
        char buf[10];

        if (read(pdesk[0], buf, 10) == -1) {
            perror("Blad odczytu z potoku");
            exit(1);
        }

        printf("Odczytano z potoku: %s\n", buf);
    }

    return 0;
}
