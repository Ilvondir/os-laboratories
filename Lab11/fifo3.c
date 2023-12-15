#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fifo3.c\n\n");
    
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
        close(1);

        fdesk = open("/tmp/fifo", O_WRONLY);

        if (fdesk == -1) {
            perror("Blad otwarcia kolejki do zapisu ");
            exit(1);
        }

        if (fdesk != 1) {
            perror("Niewlasciwy deskryptor do zapisu ");
            exit(1);
        }

        execvp("ls", argv);

        perror("Blad uruchmienia programu ");
        exit(1);
    }

    if (pid > 0) {
        close(0);

        fdesk = open("/tmp/fifo", O_RDONLY);

        if (fdesk == -1) {
            perror("Blad otwarcia kolejki do odczytu ");
            exit(1);
        }

        if (fdesk != 0) {
            perror("Niewlasciwy deskryptor do odczytu ");
            exit(1);
        }

        execlp("tr", "tr", "a-z", "A-Z", NULL);

        perror("Blad uruchomienia programu tr ");
    }

    return 0;
}
