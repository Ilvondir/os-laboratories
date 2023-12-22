#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define N 20000
#define MAX 4

int main() {
    int shmid = shmget(IPC_PRIVATE, MAX*sizeof(int), IPC_CREAT | 0600);

    if (shmid == -1) {
        perror("Tworzenie segmentu pamieci wspoldzielonej ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        int *mem = (int*)shmat(shmid, NULL, 0);

        int i;
        for (i = 0; i < N; i++) mem[i % MAX] = i;

        printf("Child finished writing to shared memory.\n");

        shmdt(mem);
    }

    if (pid > 0) {
        int *mem = (int*)shmat(shmid, NULL, 0);

        printf("Parent read: ");
        
        wait(NULL);

        int i;
        for (i = 0; i < MAX; i++) printf("%d ", mem[i]);

        printf("\n");

        shmdt(mem);

        shmctl(shmid, IPC_RMID, (struct shmid_ds*)0);
    }

    exit(0);
}

