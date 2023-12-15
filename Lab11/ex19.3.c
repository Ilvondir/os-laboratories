#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ex19.3.c\n\n");

    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if (pid == 0) {

        pid_t pid2 = fork();

        if (pid2 == 0) {
            close(pdesk[0]);
        
            dup2(pdesk[1], 1);

            execlp("ls", "ls", NULL);
        }

        if (pid2 != 0) {
            wait(NULL);
            
            dup2(pdesk[0], 0);

            execlp("grep", "grep", "^e", NULL);
        }
    }

    if (pid != 0) {
        wait(NULL);

        close(pdesk[1]);

        execlp("more", "more", NULL);
    }

    return 0;
}

// gcc ex19.3.c -o ex19.3 -Wall