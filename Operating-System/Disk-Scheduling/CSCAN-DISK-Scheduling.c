#include <stdio.h>
#include <stdlib.h>

void sort(int[], int);
void cscan(int[], int, int);

void main()
{
    int diskQueue[20], n, head;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the head : ");
    scanf("%d", &head);
    printf("Enter the Queue : ");
    for (int i = 1; i < n; i++)
        scanf("%d", &diskQueue[i]);
    diskQueue[0] = head;
    diskQueue[n++] = 0;
    diskQueue[n++] = 199;
    sort(diskQueue, n);
    cscan(diskQueue, n, head);
}

void sort(int diskQueue[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (diskQueue[j] > diskQueue[j + 1])
            {
                int temp = diskQueue[j];
                diskQueue[j] = diskQueue[j + 1];
                diskQueue[j + 1] = temp;
            }
        }
    }
}

void cscan(int diskQueue[], int n, int head)
{

    int pos, diff, seektime = 0, curr;
    for (int i = 0; i < n; i++)
    {
        if (diskQueue[i] == head)
        {
            pos = i;
            break;
        }
    }
    for (int i = pos; i < n - 1; i++)
    {
        diff = abs(diskQueue[i + 1] - diskQueue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n", diskQueue[i], diskQueue[i + 1], diff);
    }
    curr = n - 1;
    for (int i = 0; i < pos; i++)
    {
        diff = abs(diskQueue[curr] - diskQueue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n", curr, diskQueue[i], diff);
        curr = i;
    }
    printf("SeekTime is = %d", seektime);
}

/*
Enter the size of Queue: 9
Enter the head : 50
Enter the Queue : 176 79 34 60 92 11 41 114
50 -> 60 : 10
60 -> 79 : 19
79 -> 92 : 13
92 -> 114 : 22
114 -> 176 : 62
176 -> 199 : 23
199 -> 0 : 199
0 -> 11 : 11
11 -> 34 : 23
34 -> 41 : 7
SeekTime is = 389
*/