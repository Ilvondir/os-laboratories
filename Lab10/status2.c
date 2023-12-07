#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("status2.c\n\n");
    
    pid_t pid1 = fork();

    if (pid1 == 0) { // proces dziecko
        sleep(10);
        exit(7);
    }

    printf("pid rodzica = %d\n", getpid());
    printf("pid dziecka = %d\n\n", pid1);

    kill(pid1, 9);

    int status;

    pid_t pid2 = wait(&status);

    printf("Proces: %d\n", pid2);
    printf("Status: %x\n", status);
}
