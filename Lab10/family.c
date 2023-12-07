#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("family.c\n\n");

    fork();

    printf("Pierwszy fork - pid = %d\n", getpid());
    printf("Pierwszy fork - ppid = %d\n", getppid());

    fork();

    printf("Drugi fork - pid = %d\n", getpid());
    printf("Drugi fork - ppid = %d\n", getppid());

    return 0;
}
