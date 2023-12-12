#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, start;
    char line[50], name[50], staadr[200];
    FILE *fp;
    fp = fopen("absolute.txt", "r");
    fscanf(fp, "%s", line);
    for (i = 2, j = 0; line[i] != '^'; i++, j++)
        name[j] = line[i];
    name[j] = '\0';
    printf("PROGRAM NAME = %s\n\n", name);

    while (fscanf(fp, "%s", line) != EOF)
    {
        if (line[0] == 'T')
        {
            for (i = 2, j = 0; line[i] != '^'; i++, j++)
                staadr[j] = line[i];
            staadr[j] = '\0';
            start = atoi(staadr);
            i = 12;
            while (line[i] != '$')
            {
                if (line[i] != '^')
                {
                    printf("00%d\t%c%c\n", start, line[i], line[i + 1]);
                    start++;
                    i += 2;
                }
                else
                {
                    i++;
                }
            }
        }
        if (line[0] == 'E')
        {
            fclose(fp);
            break;
        }
    }
    return 0;
}

/*
PROGRAM NAME = COPY

001000	00
001001	10
001002	03
001003	00
001004	11
001005	22
002000	01
002001	0B
002002	0A
*/