#include <stdio.h>

void main()
{
    int n, bt[20], wt[20], tat[20];
    float awt = 0.0, atat = 0.0;
    printf("Enter the size : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time %d : ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
    wt[0] = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + bt[i];
        tat[i] = wt[i + 1];
        awt += wt[i];
        atat += tat[i];
    }
    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t %d\t\t\t %d\t\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    printf("Avearge Waiting time : %f\n", (awt / n));
    printf("Avearge TurnAround time : %f", (atat / n));
}

/*
Enter the size : 3
Burst Time 1 : 3
Burst Time 2 : 3
Burst Time 3 : 24

Process  Burst Time      Waiting Time    Turnaround Time
1                3                       0                       3
2                3                       3                       6
3                24                      6                       30
Avearge Waiting time : 3.000000
Avearge TurnAround time : 13.000000
*/