#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define MAX 5

int main() {
    int shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT | 0600);

    if (shmid == -1) {
        perror("Utworzenia segmentu pamieci wspoldzielonej ");
        exit(1);
    }

    int *mem = (int*)shmat(shmid, NULL, 0);

    if (mem == (void*)-1) {
        perror("Przylaczenia segmentu pamieci wspoldzielonej ");
        exit(1);
    }

    printf("mread : mem = %p\n\n", mem);

    printf("Data received:");

    int i;
    for (i = 0; i < MAX; i++) printf(" %d", mem[i]);

    printf("\n");

    shmdt(mem);

    shmctl(shmid, IPC_RMID, (struct shmid_ds*)0);

    system("ipcs -m");

    return 0;
}

