#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 512

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("fifo3err.c\n\n");
    
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

        if (fdesk == -1){
            perror("Blad otwarcia kolejki do zapisu ");
            exit(1);
        }

        if (fdesk != 1){
            perror("Niewlasciwy deskryptor do zapisu ");
            exit(1);
        }

        execvp("ls", argv);

        perror("Blad uruchmienia programu ");
        exit(1);
    }

    if (pid > 0) {
        close(0);

        wait(NULL);

        fdesk = open("/tmp/fifo", O_RDONLY);

        char buf[MAX];
        int lb, i;

        while ((lb = read(fdesk, buf, MAX)) > 0) {
            for (i = 0; i < lb; i++)
                buf[i] = toupper(buf[i]);

            if (write(1, buf, lb) == -1) {
                perror("Blad zapisu na standardowe wyjscie ");
                exit(1);
            }
        }

        if (lb == -1) {
            perror("Blad odczytu z kolejki ");
            exit(1);
        }
    }

    return 0;
}
