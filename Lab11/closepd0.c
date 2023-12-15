#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
  gcc closepd0.c -o closepd0
*/

void sigHandler(int signum) {
    psignal(signum, "Signal SIGPIPE ");
}

int main() {
    printf("closepd0.c\n\n");
    
    signal(SIGPIPE, sigHandler); // register signal handler

    int pdesc[2];

    if (pipe(pdesc) == -1) {
        perror("Blad tworzenia potoku ");
        exit(1);
    }

    close(pdesc[0]);

    if (write(pdesc[1], "0", 1) == -1) {
        perror("Blad zapisu do potoku ");

        exit(1);
    }

    exit(0);
}

