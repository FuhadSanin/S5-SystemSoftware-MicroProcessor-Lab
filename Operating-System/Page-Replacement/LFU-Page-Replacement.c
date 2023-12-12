#include <stdio.h>

void LFU(int[], int[], int, int, int[]);

int main()
{
    int i, pCount, fCount, pages[30], frames[20], count[20];
    printf("Number of Frames : ");
    scanf("%d", &fCount);
    // create frames array will null value
    for (i = 0; i < fCount; ++i)
        frames[i] = -1;
    printf("Number of Pages : ");
    scanf("%d", &pCount);
    printf("Enter the reference string\n");
    for (i = 0; i < pCount; ++i)
    {
        scanf("%d", &pages[i]);
    }
    // call the function
    LFU(pages, frames, pCount, fCount, count);

    return 0;
}

void LFU(int pages[], int frames[], int pCount, int fCount, int count[])
{
    int i, j, k, flag, queue = 0, hitCount = 0, faultCount = 0, pos;
    printf("Ref String\t|Sequence\n");
    for (i = 0; i < pCount; i++)
    {
        printf("%d\t|", pages[i]);
        flag = 0;
        for (j = 0; j < fCount; j++)
        {
            // Hit condition
            if (frames[j] == pages[i])
            {
                flag = 1;
                count[j]++;
                hitCount++;
                break;
            }
        }
        if (flag == 0)
        {
            if (queue < fCount)
            {
                frames[queue] = pages[i];
                count[frames[queue]]++;
                queue += 1;
            }
            else
            {
                pos = 0;
                for (j = 1; j < fCount; j++)
                {
                    if (count[j] < count[pos])
                        pos = j;
                }
                frames[pos] = pages[i];
                count[pos] = 1;
            }
        }
        if (flag == 1)
            printf("Hit\n\n");
        else
        {
            faultCount++;
            for (j = 0; j < fCount; j++)
                printf("%d ", frames[j]);
            printf("\n\n");
        }
    }
    printf("Total Page Faults = %d\n\n", faultCount);
    printf("Total Hits = %d\n\n", hitCount);
}

/*
Number of Frames : 3
Number of Pages : 7
Enter the reference string
1 2 3 4 2 1 5
Ref String      |Sequence
1       |1 -1 -1

2       |1 2 -1

3       |1 2 3

4       |4 2 3

2       |Hit

1       |1 2 3

5       |5 2 3

Total Page Faults = 6

Total Hits = 1
*/