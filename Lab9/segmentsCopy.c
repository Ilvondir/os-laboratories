#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void copyChars(int fd) {

    int dest = creat("chars.txt", 0777);

    if (dest == -1) {
        perror("Error: ");
        exit(1);
    }

    char buf[1];

    int i = 0;
    while (i < 10) {
        lseek(fd, -1*(i+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);

        i++;
    }

    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

void copyWords(int fd) {

    int dest = creat("words.txt", 0777);

    if (dest == -1) {
        perror("Error: ");
        exit(1);
    }

    char buf[1];
    int i = 0;
    int temp = 0;
    while (i < 10) {
        lseek(fd, -1*(temp+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);

        if (buf[0] == ' ' || buf[0] == '\n') i++;
        temp++;
    }


    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

void copyLines(int fd) {

    int dest = creat("lines.txt", 0777);

    if (dest == -1) {
        perror("Error: ");
        exit(1);
    }

    char buf[1];
    int i = 0;
    int temp = 0;
    while (i < 10) {
        lseek(fd, -1*(temp+1), SEEK_END);
        int readed = read(fd, buf, 1);
        write(dest, buf, readed);

        if (buf[0] == '\n') i++;
        temp++;
    }


    if (close(dest) == -1) {
        perror("Error: ");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    printf("segmentsCopy.c\n\n");

    int source_file = open("base.txt", O_RDONLY);

    if (source_file == -1) {
        perror("Error: ");
        exit(1);
    }

    copyChars(source_file);

    copyWords(source_file);

    copyLines(source_file);

    if (close(source_file) == -1) {
        perror("Error: ");
        exit(1);
    }

    exit(0);
}

/* 
    gcc segmentsCopy.c -o segmentsCopy
*/