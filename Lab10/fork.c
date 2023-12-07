#include <stdio.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fork.c\n\n");
    
    printf("Poczatek\n");

    fork();

    printf("Koniec\n");

    return 0;
}
