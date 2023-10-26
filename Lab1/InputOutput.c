#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("InputOutput.c\n\n");

    int a;
    float b;
    char c[10];
    char e[20];
    char f[20];

    printf("a = ");
    scanf("%d", &a);

    printf("int value a = %d\n\n", a);

    printf("b = ");
    scanf("%f", &b);

    printf("float value b = %f\n\n", b);

    printf("c = ");
    scanf("%9s", c);

    fflush(stdin);

    printf("(fgets) c = ");
    fgets(c, 10, stdin);

    printf("string value c = %s\n\n", c);
    
    fflush(stdin);

    double d;

    printf("d = ");
    scanf("%lf", &d);

    printf("double value d = %lf\n\n", d);
    
    fflush(stdin);

    printf("Enter text: ");
    scanf("%19[^\n]", &e);

    printf("Text: %s\n\n", e);

    fflush(stdin);

    printf("Enter text: ");
    fgets(f, 19, stdin);

    printf("Text: %s", f);

    fflush(stdin);

    return 0;
}
