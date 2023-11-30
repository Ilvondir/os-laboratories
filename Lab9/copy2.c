#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("copy2.c\n\n");

    if (argc != 3) {
        printf("You must give 3 arguments!");
        exit(1);
    }

    char bufor[1024];
    int source_file, dest_file, readed;

    source_file = open(argv[1], O_RDONLY);
    dest_file = creat(argv[2], 0777);

    if (source_file == -1 || dest_file == -1) {
        perror("Error: ");
        exit(1);
    }

    while ((readed = read(source_file, bufor, 1024)) > 0) {
        int w_st = write(dest_file, bufor, readed);
        if (w_st == -1) perror("Error: ");
    }

    if (close(source_file) == -1 || close(dest_file) == -1) {
        perror("Error: ");
    }

    return 0;
}

/*
gcc -o copy2 copy2.c
*/