
#include <stdio.h>

int main()
{
    int n, i, tq, bt[10], rem[10], wt[10], tat[10], time = 0, done;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    if (n < 1 || n > 10 || tq <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    do
    {
        done = 1;

        for (i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                done = 0;

                if (rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
