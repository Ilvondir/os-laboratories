#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fibo1(int x) {
    if (x == 1 || x == 0) {
        printf("fibo1(%d) = 1\n", x);
        return 1;
    }

    int pom = 1;
    int r0 = 1;
    int r1 = 2;

    int i = 0;
    for(i=0; i<x-2; i++) {
        pom = r0;
        r0 = r1;
        r1 = pom + r0;
    }

    printf("fibo1(%d) = %d\n", x, r1);

    return fibo1(x-1) + fibo1(x-2);
}

int main(int argc, char *argv[]) {
    printf("fiboTree.c\n\n");

    fibo1(4);

    return 0;
}
