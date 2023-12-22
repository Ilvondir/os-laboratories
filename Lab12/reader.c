#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>

#define N 80

struct msgbuf {
    long mtype;
    char mvalue[N];
};

int main() {
    int msgid = msgget(45281, IPC_CREAT | 0600);

    struct msgbuf msg;

    msgrcv(msgid, &msg, sizeof(msg.mvalue), 1, 0);

    printf("Message received: %s\n", msg.mvalue);

    system("ipcs -q");

    //msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

