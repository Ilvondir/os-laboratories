#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pdesc[2];

    if (pipe(pdesc) == -1) {
        perror("Blad tworzenia potoku ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        printf("Parent is blocked for two seconds.\n");

        sleep(2);

        close(pdesc[1]);

        printf("Parent will read 0 bytes and exit.\n");
    }

    if (pid > 0) {
        close(pdesc[1]);

        char buf[1];

        int bytes = read(pdesc[0], buf, 1);

        printf("Parent has read %d bytes and exits.\n", bytes);
    }

    exit(0);
}

// gcc closepd1.c -o closepd1 -Wall
