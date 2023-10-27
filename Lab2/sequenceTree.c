#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float a1(int x) {
    if (x == 0) {
        printf("a1(%d) = 1\n", x);
        return 1;
    }
    if (x == 1) {
        printf("a1(%d) = 4\n", x);
        return 4;
    }

    float pom = 1;
    float r0 = 4;
    float r1 = 8.5f;

    int i;
    for(i=0; i<x-2; i++) {
        pom = r0;
        r0 = r1;
        r1 = 0.5f*pom + 2*r0;
    }

    printf("a1(%d) = %f\n", x, r1);

    return 2.0f*a1(x-1) + 0.5f*a1(x-2);
}

int main(int argc, char *argv[]) {
    printf("sequenceTree.c\n\n");

    a1(4);

    return 0;
}
