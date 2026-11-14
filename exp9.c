
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int id, *data;
    id = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);
    data = (int *)shmat(id, NULL, 0);

    if (fork() == 0)
    {
        *data = 100;
        printf("Child writes: %d\n", *data);
        shmdt(data);
    }
    else
    {
        wait(NULL);
        printf("Parent reads: %d\n", *data);
        shmdt(data);
        shmctl(id, IPC_RMID, NULL);
    }

    return 0;
}
