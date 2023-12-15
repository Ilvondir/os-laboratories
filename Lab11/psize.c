#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
  gcc psize.c -o psize -Wall
*/

int main() {
    printf("psize.c\n\n");
    
    int pdesk[2];

    if (pipe(pdesk) == -1) {
        perror("Blad tworzenia potoku ");
        exit(1);
    }

    int psize = fcntl(pdesk[0], F_GETPIPE_SZ);

    printf("psize = %d\n", psize);

    return 0;
}
