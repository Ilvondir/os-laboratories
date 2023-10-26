#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
    0   1   2   3   4   5   6    indeksy
    1   1   2   3   5   8   13   wartosci
*/
int fibo1(int x) {
//    printf("x = %d\n", x);

    if (x == 1 || x == 0) return 1;

    return fibo1(x-1) + fibo1(x-2);
}

/*
    r0  r1  r2
    |---|---|
    0   1   2   3   4   5   6    indeksy
    1   1   2   3   5   8   13   wartości
        |---|---|
        r0  r1  r2
 */
int fibo2(int x) {
    int r0 = 1;
    int r1 = 1;
    int r2 = 2;

//    printf("r0 = %d, r1 = %d, r2 = %d\n", r0, r1, r2);

    int i = 0;
    for (i=0;i<x-2; i++) {
        r0 = r1;
        r1 = r2;
        r2 = r1 + r0;
//        printf("r0 = %d, r1 = %d, r2 = %d\n", r0, r1, r2);
    }

    return r2;
}

/*
r0  r1
|---|
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartości
|   |---|
pom r0  r1
*/
int fibo3(int x) {
    int pom = 1;
    int r0 = 1;
    int r1 = 2;

//    printf("r0 = %d, r1 = %d\n", r0, r1);

    int i = 0;
    for(i; i<x-2; i++) {
        pom = r0;
        r0 = r1;
        r1 = pom + r0;
//        printf("r0 = %d, r1 = %d\n", r0, r1);
    }

    return r1;
}

int main(int argc, char *argv[]) {
    printf("fibo.c\n\n");

    int n = 4;

    printf("fibo1(%d) = %d\n", n, fibo1(n));
    printf("fibo2(%d) = %d\n", n, fibo2(n));
    printf("fibo3(%d) = %d\n", n, fibo3(n));

    return 0;
}
