#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fwriterFIFO.c\n\n");
    
    if (mkfifo("kolFIFO", 0600) == -1) {
        perror("Blad tworzenia kolejki FIFO ");
        exit(1);
    }

    int fdesc = open("kolFIFO", O_WRONLY);

    if (fdesc == -1){
        perror("Blad otwarcia kolejki do zapisu ");
        exit(1);
    }

    printf("fwriter : fdesc = %d\n", fdesc);

    char msg[] = "Message from fwriter.";

    write(fdesc, msg, strlen(msg) + 1);

    printf("Message sent: %s\n", msg);

    return 0;
}

// gcc fwriterFIFO.c -o fwriterFIFO -Wall
