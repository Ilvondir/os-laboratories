#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fifo.c\n\n");
    
    mkfifo("kolFIFO", 0600);

    open("kolFIFO", O_RDONLY);

    return 0;
}

// gcc fifo.c -o fifo -Wall
