#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>

#define N 80

struct msgbuf {
    long mtype;
    char mvalue[N];
};

int main() {
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0600);

    if (msgid == -1) {
        perror("Utworzenia kolejki komunikatow ");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        struct msgbuf msg;

        msg.mtype = 1;
        strcpy(msg.mvalue, "Message from the child.");

        printf("Child will send a message in 3 seconds.\n");

        sleep(3);

        if (msgsnd(msgid, &msg, sizeof(msg.mvalue), 0) == -1) {
            perror("Wysylania komunikatu ");
            exit(1);
        }
    }

    if (pid > 0) {
        struct msgbuf msg;

        if (msgrcv(msgid, &msg, sizeof(msg.mvalue), 1, 0) == -1) {
            perror("Odbierania komunikatu ");
            exit(1);
        }

        printf("Parent received: %s\n", msg.mvalue);

        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("Usuwania kolejki ");
            exit(1);
        }
    }

    exit(0);
}

