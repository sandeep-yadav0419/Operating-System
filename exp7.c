
#include <stdio.h>
int main()
{
    int n, i, j, at[10], bt[10], ct[10], tat[10], wt[10], p[10], temp, time = 0, min;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter arrival time and burst time of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        min = -1;

        for (j = 0; j < n; j++)
        {
            if (at[j] <= time && bt[j] > 0)
            {
                if (min == -1 || bt[j] < bt[min])
                    min = j;
            }
        }
        if (min == -1)
        {
            time++;
            i--;
            continue;
        }
        time += bt[min];
        ct[min] = time;
        tat[min] = ct[min] - at[min];
        wt[min] = tat[min] - bt[min];
        bt[min] = 0;
    }
    printf("\nProcess\tAT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], ct[i], tat[i], wt[i]);
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}
