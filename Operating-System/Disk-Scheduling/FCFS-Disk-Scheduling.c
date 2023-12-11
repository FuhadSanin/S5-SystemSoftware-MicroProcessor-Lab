#include <stdio.h>
#include <stdlib.h>

void main()
{
    int diskQueue[20], n, seektime=0, diff;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue : ");
    for (int i = 1; i < n; i++)
        scanf("%d", &diskQueue[i]);
    printf("Enter the head : ");
    scanf("%d", &diskQueue[0]);
    for (int i = 0; i < n - 1; i++)
    {
        diff = abs(diskQueue[i + 1] - diskQueue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n", diskQueue[i], diskQueue[i + 1], diff);
    }
    printf("Seektime : %d\n", seektime);
    printf("Avg Seektime : %f", (float)seektime / n);
}

/*
Enter the size of Queue: 9
Enter the Queue : 176 79 34 60 92 11 41 114
Enter the head : 50
50 -> 176 : 126
176 -> 79 : 97
79 -> 34 : 45
34 -> 60 : 26
60 -> 92 : 32
92 -> 11 : 81
11 -> 41 : 30
41 -> 114 : 73
Seektime : 510
Avg Seektime : 56.666668
*/