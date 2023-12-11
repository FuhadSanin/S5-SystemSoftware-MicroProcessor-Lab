#include <stdio.h>

void main()
{
    int n, at[20], bt[20], rt[20], wt[20], tat[20], remain, q;
    float awt = 0.0, atat = 0.0;
    printf("Enter the size : ");
    scanf("%d", &n);
    remain = n;
    printf("Arival time and Burst Time : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the time Quantum : ");
    scanf("%d", &q);
    int i = 0, time = 0, flag = 0;
    while (remain != 0)
    {
        if (rt[i] <= q && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            time += q;
            rt[i] -= q;
        }
        if (flag == 1 && rt[i] == 0)
        {
            remain--;
            wt[i] = time - at[i] - bt[i];
            tat[i] = time - at[i];
            awt += wt[i];
            atat += tat[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= time)
            i++;
        else
            i = 0;
    }
    printf("\nProcess\t Arrival Time\t Burst Time\t  Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    printf("\nAvg Waiting time : %f", awt / n);
    printf("\nAvg TurnAround time : %f", atat / n);
}
/*
Enter the size : 4
Arival time and Burst Time : 0 5 1 4 2 2 4 1
Enter the time Quantum : 2

Process  Arrival Time    Burst Time       Waiting Time   Turnaround Time
1                0               5               7               12
2                1               4               6               10
3                2               2               2               4
4                4               1               2               3

Avg Waiting time : 4.250000
Avg TurnAround time : 7.250000
*/