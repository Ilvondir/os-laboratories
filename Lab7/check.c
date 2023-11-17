#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("check.c\n\n");
    
    printf("Program compiled on: ");
    
    #ifdef linux
        printf("Linux\n");
    #else
        printf("Windows\n");
    #endif

    return 0;
}
