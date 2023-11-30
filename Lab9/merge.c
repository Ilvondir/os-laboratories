#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("merge.c\n\n");

    if (argc <= 2) {
        printf("As arguments you will input list of files and destination file.\n");
        exit(1);
    }

    int dest = creat(argv[argc-1], 0777);

    if (dest == -1) {
        perror("Error: ");
        exit(1);
    }

    int i;
    for (i = 1; i < argc-1; i++) {

        int cur = open(argv[i], O_RDONLY);

        if (cur == -1) {
            perror("Error: ");
            exit(1);
        }

        char buf[100];
        int readed;

        while ((readed = read(cur, buf, 100)) > 0) { 
            write(dest, buf, readed);
        }

        if (close(cur) == -1) {
            perror("Error: ");
            exit(1);
        }
    }

    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}
