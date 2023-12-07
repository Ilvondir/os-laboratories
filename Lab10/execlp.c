#include <stdio.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("execlp.c\n\n");
    
    printf("Poczatek\n");

    execlp("ls", "ls", "-l", NULL);

    printf("Koniec\n");

    return 0;
}
