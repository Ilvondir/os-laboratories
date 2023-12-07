#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fork2.c\n\n");
    
    printf("Poczatek\n");

    pid_t pid = fork();

    if (pid < 0) fprintf(stderr, "Blad tworzenia procesu potomnego.\n");

    if (pid == 0) printf("Proces dziecko, zmienna pid = %d\n", pid);

    if (pid > 0) printf("Proces rodzic, zmienna pid = %d\n", pid);

    printf("Koniec\n");
    
    return 0;
}
