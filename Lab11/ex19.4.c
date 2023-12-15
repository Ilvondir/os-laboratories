#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ex19.4.c\n\n");

    int pdesk[2];

    if (pipe(pdesk) == -1) {
        perror("Error: ");
        exit(1);
    }

    pid_t pid1 = fork();

    if (pid1 == 0) {

        pid_t pid2 = fork();

        if (pid2 == 0) {

            dup2(pdesk[1], 1);

            execlp("ps", "ps", "-ef", NULL);
        }

        if (pid2 != 0) {
            wait(NULL);

            dup2(pdesk[0], 0);

            execlp("tr", "tr", "-s", "' '", ":", NULL);         
        }
    }

    return 0;
}

// ps -ef| tr -s ' '  :| cut -d: -f1 |sort| uniq -c |sort n

// gcc ex19.4.c -o ex19.4 -Wall