#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define MAX 5

int main() {
    int shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT | 0600);

    if (shmid == -1) {
        perror("Tworzenie segmentu pamieci wspoldzielonej ");
        exit(1);
    }

    int *mem = (int*)shmat(shmid, NULL, 0);

    if (mem == (void*)-1) {
        perror("Przylaczanie segmentu pamieci wspoldzielonej ");
        exit(1);
    }

    printf("mwrite : mem = %p\n\n", mem);

    int i;
    for (i = 0; i < 2*MAX; i++) mem[i % MAX] = i;

    printf("Data written to shared memory.\n");

    shmdt(mem);

    system("ipcs -m");

    return 0;
}

