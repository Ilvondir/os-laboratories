#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("zombies.c\n\n");

    int pid;

    pid = fork();
    if (pid == 0) {
      printf("1. zombie pid = %d\n", getpid());
      exit(0);
    }

    pid = fork();
    if (pid == 0) {
      printf("2. zombie pid = %d\n", getpid());
      exit(0);
    }

    pid = fork();
    if (pid == 0) {
      printf("3. zombie pid = %d\n", getpid());
      exit(0);
    }

    sleep(20);
    
    wait(NULL);

    exit(0);

    return 0;
}

/*
  gcc zombies.c -o zombies -Wall
  ps -e -o pid,ppid,comm,stat
*/