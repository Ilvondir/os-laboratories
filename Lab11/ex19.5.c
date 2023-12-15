#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("ex19.5.c\n\n");

    int pdesk[2];

    pipe(pdesk);

    pid_t pid = fork();

    if (pid == 0) {
        close(pdesk[0]);
        dup2(pdesk[1], 1);

        execlp("cat", "cat", "/etc/group", NULL);
    }

    wait(NULL);

    pid = fork();

    if (pid == 0) {
        dup2(pdesk[0], 0);

        int desk = creat("grupy.txt", 0777);

        dup2(desk, 1);

        execlp("head", "head", "-5", NULL);
    }
  
    wait(NULL);

    return 0;
}

// cat /etc/group | head -5 > grupy.txt
// gcc ex19.5.c -o ex19.5 -Wall