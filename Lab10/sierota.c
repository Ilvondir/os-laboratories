#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("sierota.c\n\n");
    
    if (fork() == 0) {
        printf("child pid = %d\n", getpid());

        sleep(20);

        exit(0);
    }

    exit(0);
}

/*
  gcc sierota.c -o sierota -Wall
  ps -e -o pid,ppid,comm,stat
*/
