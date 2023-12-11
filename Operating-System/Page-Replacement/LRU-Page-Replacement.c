#include <stdio.h>

void LRU(int[], int[], int, int, int[], int);
int findPos(int[], int);

int main()
{
    int i, pCount, fCount, pages[30], frames[20], time[30], counter = 0;
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
    LRU(pages, frames, pCount, fCount, time, counter);

    return 0;
}

void LRU(int pages[], int frames[], int pCount, int fCount, int time[], int counter)
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
                printf(" Hit\n\n");
                hitCount++;
                counter++;
                time[j] = counter;
                break;
            }
        }
        if (flag == 0 && queue < fCount)
        {
            counter++;
            faultCount++;
            frames[queue] = pages[i];
            time[queue] = counter;
            queue++;
        }
        else if (flag == 0 && queue == fCount)
        {
            counter++;
            faultCount++;
            pos = findPos(time, fCount);
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        if (flag == 0)
        {
            for (k = 0; k < fCount; ++k)
            {
                printf("%d  ", frames[k]);
            }
            printf("\n\n");
        }
    }
    printf("Total Page Faults = %d\n\n", faultCount);
}

int findPos(int time[], int fCount)
{
    int pos = 0, min = time[0];
    for (int k = 1; k < fCount; k++)
    {
        if (min > time[k])
        {
            min = time[k];
            pos = k;
        }
    }
    return pos;
}
/*

Number of Frames : 3
Number of Pages : 20
Enter the reference string
9 2 3 1 2 5 3 4 6 9 9 1 0 5 4 6 2 3 0 1
Ref String      |Sequence
---------------------------

9       |9  -1  -1

2       |9  2  -1

3       |9  2  3

1       |1  2  3

2       | Hit

5       |1  2  5

3       |3  2  5

4       |3  4  5

6       |3  4  6

9       |9  4  6

9       | Hit
1       |9  1  6

0       |9  1  0

5       |5  1  0

4       |5  4  0

6       |5  4  6

2       |2  4  6

3       |2  3  6

0       |2  3  0

1       |1  3  0

Total Page Faults = 18



...Program finished with exit code 0
Press ENTER to exit console.
*/