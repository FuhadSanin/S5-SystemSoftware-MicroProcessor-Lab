#include <stdio.h>

void main()
{
    int n, at[20], bt[20], ct[20], wt[20], tat[20];
    float awt = 0.0, atat = 0.0;
    printf("Enter the size : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Arival time and Burst Time %d : ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    ct[0] = 0;
    for (int i = 0; i < n; i++)
    {
        ct[i + 1] = ct[i] + bt[i];
        wt[i] = ct[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    printf("Avearge Waiting time : %f\n", (awt / n));
    printf("Avearge TurnAround time : %f", (atat / n));
}

/*
Enter the size : 4
Arival time and Burst Time 1 : 0 5
Arival time and Burst Time 2 : 1 3
Arival time and Burst Time 3 : 2 8
Arival time and Burst Time 4 : 3 6

Process  Arrival Time    Burst Time      Completion Time         Waiting Time    Turnaround Time
1                0               5               0                       0                       5
2                1               3               5                       4                       7
3                2               8               8                       6                       14
4                3               6               16                      13                      19
Avearge Waiting time : 5.750000
Avearge TurnAround time : 11.250000
*/