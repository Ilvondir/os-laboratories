#include <regex.h>
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("regexp.c\n\n");

    char text[] = "12TeST";
    char pattern[] = "[3-9a-z./]";

    regex_t regex;
    int reti;

    // Kompilacja wzorca
    reti = regcomp(&regex, pattern, 0);

    if (reti) {
        fprintf(stderr, "Nie można skompilować wyrażenia regularnego\n");
        return 1;
    }

    reti = regexec(&regex, text, 0, NULL, 0);

    if (!reti) {
        printf("Znaleziono dopasowanie: \"%s\"\n", pattern);
    } else if (reti == REG_NOMATCH) {
        printf("Brak dopasowania.\n");
    } else return 1;

    return 0;
}