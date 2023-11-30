#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("compare.c\n\n");

    if (argc != 3) {
        printf("As arguments you will input 2 files to compare.\n");
        exit(1);
    }

    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[2], O_RDONLY);

    if (f1 == -1 || f2 == -1) {
        perror("Error: ");
        exit(1);
    }

    char buf1[1];
    char buf2[1];
    int line = 1;
    int i=1;
    int expanded = 0, bigger_file, smaller_file;
    int same = 1;

    while (1) {
        int r1 = read(f1, buf1, 1);
        int r2 = read(f2, buf2, 1);

        if (r1 == 0 || r2 == 0) {
            if (r1 != r2) {
                same = 0;
                expanded = 1;
                bigger_file = r1==0 ? 2 : 1;
                smaller_file = r1==0 ? 1 : 2;
                break;
            }

            if (r1 == r2) break;
        }

        if ((buf1[0] != buf2[0])) {
            same = 0;
            printf("Pliki różnią się od znaku nr %d w linii %d\n", i, line);
            break;
        }

        if (buf1[0] == '\n') line++;
        i++;
    }

    if (same) printf("Pliki sa identyczne.\n");

    if (expanded) {
        int remaining;

        if (bigger_file == 1) remaining = lseek(f1, 0, SEEK_END) - (i-1);
        else remaining = lseek(f2, 0, SEEK_END) - (i-1);

        printf("Plik %s zawiera %d znakow wiecej niż zawartosc pliku %s\n", argv[bigger_file], remaining, argv[smaller_file]);
    }

    if (close(f1) == -1 || close(f2) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}
