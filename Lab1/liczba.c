#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("liczba.c\n\n");

    int n;

    printf("Enter number:");
    scanf("%d", &n);

    printf("%d digits", (int)floor(log10(n))+1);

    return 0;
}
