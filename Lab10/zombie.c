#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("zombie.c\n\n");
    
    if (fork() == 0) {
        printf("child pid = %d\n", getpid());
        exit(0);
    }

    sleep(20);
    
    wait(NULL);

    exit(0);
}

/*
  gcc zombie.c -o zombie -Wall
  ps -e -o pid,ppid,comm,stat
*/
