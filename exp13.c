
#include <stdio.h>

int main()
{
    int b[10], p[10], i, j, nb, np, choice, best;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    printf("1.First Fit  2.Best Fit  3.Worst Fit\n");
    scanf("%d", &choice);

    for (i = 0; i < np; i++)
    {
        best = -1;

        for (j = 0; j < nb; j++)
        {
            if (b[j] >= p[i])
            {
                if (choice == 1)
                {
                    best = j;
                    break;
                }
                if (best == -1 ||
                    (choice == 2 && b[j] < b[best]) ||
                    (choice == 3 && b[j] > b[best]))
                    best = j;
            }
        }

        if (best != -1)
        {
            printf("Process %d allocated to Block %d\n",
                   i + 1, best + 1);
            b[best] -= p[i];
        }
        else
            printf("Process %d not allocated\n", i + 1);
    }

    return 0;
}
