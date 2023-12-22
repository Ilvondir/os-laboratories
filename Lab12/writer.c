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

    printf("Message to be sent: ");

    fgets(msg.mvalue, N, stdin);

    msg.mtype = 1;

    msgsnd(msgid, &msg, sizeof(msg.mvalue), 0);

    system("ipcs -q");

    return 0;
}

