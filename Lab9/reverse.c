#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("reverse.c\n\n");

    const int MAX = 100;

    if (argc != 2) {
        printf("Give 1 argument (filename)!\n");
        exit(1);
    }

    char bufor[MAX];
    FILE *file_pointer;

    file_pointer = fopen(argv[1], "r+");

    if (file_pointer == NULL) {
        perror("Error: ");
        exit(1);
    }


    while (fgets(bufor, MAX, file_pointer) != NULL) {
        int left = 0;
        int right = strlen(bufor)-1;
        char temp;

        while (left < right) {
            temp = bufor[left];
            bufor[left] = bufor[right];
            bufor[right] = temp;

            left++;
            right--;
        }

        printf("%s", bufor);

        fseek(file_pointer, -strlen(bufor), SEEK_CUR);
        fputs(bufor, file_pointer);
    }



    if (fclose(file_pointer) != 0) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}

/*
    gcc reverse.c -o reverse
*/