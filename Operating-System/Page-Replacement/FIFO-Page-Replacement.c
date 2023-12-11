#include <stdio.h>

void fifo(int[], int[], int, int);

int main()
{
    int i, pCount, fCount, pages[30], frames[20];
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
    fifo(pages, frames, pCount, fCount);

    return 0;
}

void fifo(int pages[], int frames[], int pCount, int fCount)
{
    printf("Ref String\t|Frames\n");
    printf("-------------------------------\n");
    int i, j, k, faultCount = 0, hitCount = 0, queue = 0, flag;
    for (i = 0; i < pCount; i++)
    {
        printf("%d\t|\t", pages[i]);
        flag = 0;
        for (j = 0; j < fCount; j++)
        {
            // Hit Condition
            if (pages[i] == frames[j])
            {
                flag = 1;
                printf(" Hit");
                hitCount++;
                break;
            }
        }
        // No Hit Condition
        if (flag == 0)
        {
            frames[queue] = pages[i];
            queue = (queue + 1) % fCount;
            faultCount++;
            for (k = 0; k < fCount; k++)
                printf("%d ", frames[k]);
        }
        printf("\n\n");
    }
    printf("Total hitCount : %d\n", hitCount);
    printf("Total faultCount : %d", faultCount);
}

/*

Number of Frames : 3
Number of Pages : 18
Enter the reference string
9 1 2 5 3 4 6 9 9 1 0 5 4 6 2 3 0 1
Ref String      |Frames
-------------------------------
9       |       9 -1 -1

1       |       9 1 -1

2       |       9 1 2

5       |       5 1 2

3       |       5 3 2

4       |       5 3 4

6       |       6 3 4

9       |       6 9 4

9       |        Hit

1       |       6 9 1

0       |       0 9 1

5       |       0 5 1

4       |       0 5 4

6       |       6 5 4

2       |       6 2 4

3       |       6 2 3

0       |       0 2 3

1       |       0 1 3

Total hitCount : 1
Total faultCount : 17
*/
// 9 2 3 1 2 5 3 4 6 9 9 1 0 5 4 6 2 3 0 1