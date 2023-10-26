#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float seq1(int x) {

//    printf("%d\n", x);

    if (x == 1) return 1;
    if (x == 2) return 4;

    return 2.0f*seq1(x-1) + 0.5f*seq1(x-2);
}

int main(int argc, char *argv[]) {
    printf("sequence.c\n\n");

    int n = 5;

    printf("seq1(%d) = %f", n, seq1(n));

    return 0;
}
