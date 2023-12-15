#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAX 512

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("pipe4.c\n\n");
    
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
        dup2(pdesk[1], 1);

        execvp("ls", argv);

        perror("Blad uruchomiania programu ls");
        exit(1);
    }

    if (pid > 0) {
        close(pdesk[1]);

        dup2(pdesk[0], 0);

        execlp("tr", "tr", "a-z", "A-Z", NULL);

        perror("Blad uruchomiania programu tr");
    }

    return 0;

}

// gcc pipe4.c -o pipe4 -Wall
