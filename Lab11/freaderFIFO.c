#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX 80

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("freaderFIFO.c\n\n");
    
    int fdesc = open("kolFIFO", O_RDONLY);

    if (fdesc == -1) {
        perror("Blad otwarcia kolejki do odczytu ");
        exit(1);
    }

    printf("freader : fdesc = %d\n", fdesc);

    char buf[MAX];

    read(fdesc, buf, MAX);

    printf("Message received: %s\n", buf);

    return 0;
}

// gcc freaderFIFO.c -o freaderFIFO -Wall
