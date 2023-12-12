#include <stdio.h>

void LRU(int[], int[], int, int, int[], int);

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
    LRU(pages, frames, pCount, fCount, least, counter);

    return 0;
}

void LRU(int pages[], int frames[], int pCount, int fCount, int least[], int counter)
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
                hitCount++;
                break;
            }
        }
        if (flag == 0)
        {
            if (queue < fCount)
            {
                frames[queue] = pages[i];
                queue += 1;
            }
            else
            {
                for (j = 0; j < fCount; j++)
                {
                    least[j] = 0;
                    for (k = i - 1; k >= 0; k--)
                    {
                        if (frames[j] == pages[k])
                        {
                            least[k] = i - k;
                            break;
                        }
                    }
                }
                pos = 0;
                for (j = 0; j < fCount; j++)
                {
                    if (least[j] > least[pos])
                        pos = j;
                }
                frames[pos] = pages[i];
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

/*
Number of Frames : 4
Number of Pages : 13
Enter the reference string
 7 0 1 2 0 3 0 4 2 3 0 3 2
Ref String      |Sequence
7       |7 -1 -1 -1

0       |7 0 -1 -1

1       |7 0 1 -1

2       |7 0 1 2

0       |Hit

3       |3 0 1 2

0       |Hit

4       |3 0 4 2

2       |Hit

3       |Hit

0       |Hit

3       |Hit

2       |Hit

Total Page Faults = 6


*/