
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    int id;
    struct message msg;

    id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    msg.type = 1;
    strcpy(msg.text, "Hello from message queue");

    msgsnd(id, &msg, sizeof(msg.text), 0);
    msgrcv(id, &msg, sizeof(msg.text), 1, 0);

    printf("Received message: %s\n", msg.text);

    msgctl(id, IPC_RMID, NULL);

    return 0;
}
