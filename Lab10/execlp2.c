#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("execlp2.c\n\n");

    printf("Poczatek\n");

    if (fork() == 0) {
       execlp("ls", "ls", "-a", NULL);

       perror("Blad uruchomienia programu");

       exit(1);
    }

    wait(NULL);

    printf("Koniec\n");

    return 0;

}
