#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    FILE *fp1, *fp2;
    int i, j, stadd, hexadd;
    char line[100], addrs[100];

    fp1 = fopen("relocation.txt", "r");
    printf("\nEnter the actul starting address:");
    scanf("%x", &stadd);

    do
    {
        fscanf(fp1, "%s", line);
        if (line[0] == 'T')
        {
            for (i = 1, j = 0; i < 7; i++, j++)
            {
                addrs[j] = line[i];
            }
            addrs[j] = '\0';
            fp2 = fopen("temp.txt", "w");
            fprintf(fp2, "%s", addrs);
            rewind(fp2);
            fscanf(fp2, "%x", &hexadd);
            fclose(fp2);

            i = 9;
            while (line[i] != '\0')
            {
                printf("%x \t %c%c\n", hexadd + stadd, line[i], line[i + 1]);
                hexadd++;
                i = i + 2;
            }
        }
    } while (!feof(fp1));
    fclose(fp1);
}