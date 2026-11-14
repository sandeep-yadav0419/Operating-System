
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t fork_lock[5];

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % 5;

    printf("Philosopher %d is thinking\n", id + 1);

    pthread_mutex_lock(&fork_lock[left]);
    pthread_mutex_lock(&fork_lock[right]);

    printf("Philosopher %d is eating\n", id + 1);
    sleep(1);

    pthread_mutex_unlock(&fork_lock[right]);
    pthread_mutex_unlock(&fork_lock[left]);

    printf("Philosopher %d finished eating\n", id + 1);
    return NULL;
}

int main()
{
    pthread_t t[5];
    int id[5], i;

    for (i = 0; i < 5; i++)
    {
        pthread_mutex_init(&fork_lock[i], NULL);
        id[i] = i;
    }

    for (i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, philosopher, &id[i]);

    for (i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    for (i = 0; i < 5; i++)
        pthread_mutex_destroy(&fork_lock[i]);

    return 0;
}
