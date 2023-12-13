#include <stdio.h>

void LRU(int[], int[], int, int, int[]);

int main()
{
    int i, pCount, fCount, pages[30], frames[20], least[20], counter = 0;
    printf("Number of Frames : ");
    scanf("%d", &fCount);
    // create frames array will null value
    for (i = 0; i < fCount; ++i)
    {
        frames[i] = -1;
    }
    printf("Number of Pages : ");
    scanf("%d", &pCount);
    printf("Enter the reference string\n");
    for (i = 0; i < pCount; ++i)
    {
        scanf("%d", &pages[i]);
    }
    // call the function
    LRU(pages, frames, pCount, fCount, least);

    return 0;
}

void LRU(int pages[], int frames[], int pCount, int fCount, int least[])
{
    int i, j, k, flag, queue = 0, hitCount = 0, faultCount = 0, pos, counter = 0, time[20];
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
                hitCount++;
                counter++;
                time[j] = counter;
                break;
            }
        }
        if (flag == 0)
        {
            if (queue < fCount)
            {
                counter++;
                time[queue] = counter;
                frames[queue] = pages[i];
                queue += 1;
            }
            else
            {
                counter++;
                pos = 0;
                for (j = 0; j < fCount; j++)
                {
                    if (time[j] < time[pos])
                        pos = j;
                }
                frames[pos] = pages[i];
                time[pos] = counter;
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
}
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0

/*
Number of Frames : 3
Number of Pages : 15
Enter the reference string
7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
Ref String      |Sequence
7       |7 -1 -1

0       |7 0 -1

1       |7 0 1

2       |2 0 1

0       |Hit

3       |2 0 3

0       |Hit

4       |4 0 3

2       |4 0 2

3       |4 3 2

0       |0 3 2

3       |Hit

1       |0 3 1

2       |2 3 1

0       |2 0 1

Total Page Faults = 12
*/