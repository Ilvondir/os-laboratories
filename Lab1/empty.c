#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isInputEmpty(FILE *stream) {
    int c = fgetc(stream);
    if (c == EOF)
        return 1;  // Strumieñ wejœciowy jest pusty lub b³¹d odczytu
    else {
        ungetc(c, stream);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    printf("empty.c\n\n");

    char a[10];

    printf("Enter text: ");
    fgets(a, 9, stdin);

    if (a == EOF) printf("Empty");
    else printf("Not empty");

    //TODO: Dokonczyc

    return 0;
}
