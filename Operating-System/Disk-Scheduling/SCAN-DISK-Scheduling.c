#include <stdio.h>
#include <stdlib.h>

void sort(int[], int);
void scan(int[], int, int);

void main()
{
    int diskQueue[20], n, head;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the head : ");
    scanf("%d", &head);
    diskQueue[0] = head;
    printf("Enter the Queue : ");
    for (int i = 1; i < n; i++)
        scanf("%d", &diskQueue[i]);
    diskQueue[n++] = 199;
    sort(diskQueue, n);
    scan(diskQueue, n, head);
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

void scan(int diskQueue[], int n, int head)
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
    for (int i = pos - 1; i >= 0; i--)
    {
        diff = abs(diskQueue[curr] - diskQueue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n", diskQueue[curr], diskQueue[i], diff);
        curr = i;
    }
    printf("SeekTime is = %d", seektime);
}

/*
Enter the size of Queue: 6
Enter the head : 50
Enter the Queue :  82 170 43 140 24
50 -> 82 : 32
82 -> 140 : 58
140 -> 170 : 30
170 -> 199 : 29
199 -> 43 : 156
43 -> 24 : 19
SeekTime is = 324
*/