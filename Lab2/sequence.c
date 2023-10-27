#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float a1(int x) {
    if (x == 0) return 1;
    if (x == 1) return 4;

    return 2.0f*a1(x-1) + 0.5f*a1(x-2);
}

float a2(int x) {
    float r0 = 1;
    float r1 = 4;
    float r2 = 8.5f;

//    printf("r0 = %f, r1 = %f, r2 = %f\n", r0, r1, r2);

    int i = 0;
    for (i=1;i<x-1; i++) {
        r0 = r1;
        r1 = r2;
        r2 = 2*r1 + 0.5f*r0;
//        printf("r0 = %f, r1 = %f, r2 = %f\n", r0, r1, r2);
    }

    return r2;
}

float a3 (int x) {
    float pom = 1;
    float r0 = 4;
    float r1 = 8.5f;

//    printf("r0 = %f, r1 = %f\n", r0, r1);

    int i;
    for(i=0; i<x-2; i++) {
        pom = r0;
        r0 = r1;
        r1 = 0.5f*pom + 2*r0;
//        printf("r0 = %f, r1 = %f\n", r0, r1);
    }

    return r1;
}

int main(int argc, char *argv[]) {
    printf("sequence.c\n\n");

    int n = 4;

    printf("a1(%d) = %f\n", n, a1(n));
    printf("a2(%d) = %f\n", n, a2(n));
    printf("a3(%d) = %f\n", n, a3(n));

    return 0;
}
