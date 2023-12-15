#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fifo2.c\n\n");
    
    int fdesk;

    if (mkfifo("/tmp/fifo", 0600) == -1) {
        perror("Blad tworzenia kolejki FIFO ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Blad tworzenia procesu potomnego ");
        exit(1);
    }

    if (pid == 0) {
        fdesk = open("/tmp/fifo", O_WRONLY);

        if (fdesk == -1){
            perror("Blad otwarcia kolejki do zapisu ");
            exit(1);
        }

        if (write(fdesk, "Hallo!", 7) == -1){
            perror("Blad zapisu do kolejki ");
            exit(1);
        }

        exit(0);
    }

    if (pid > 0) {
        fdesk = open("/tmp/fifo", O_RDONLY);

        if (fdesk == -1){
            perror("Blad otwarcia kolejki do odczytu ");
            exit(1);
        }

        char buf[10];

        if (read(fdesk, buf, 10) == -1){
            perror("Blad odczytu z kolejki ");
            exit(1);
        }

        printf("Odczytano z kolejki: %s\n", buf);
    }

    return 0;
}
