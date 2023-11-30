#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("checkTxt.c\n\n");

    int fd = open("base.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error: ");
        exit(1);
    }

    char bufor[1];
    int i = 1;
    while (bufor[0] != '\0') {
        lseek(fd, i, SEEK_SET);
        read(fd, bufor, 1);

        if (!isascii(bufor[0])) {
            printf("This is not txt file.\n");
            break;
        }

        i++;
    }

    printf("This is txt file.\n");

    if (close(fd) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}
