#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, j, start, hexadr;
    FILE *fp1, *fp2;
    char line[50], adr[50];
    fp1 = fopen("relocation.txt", "r");
    printf("Enter the Starting Address : ");
    scanf("%x", &start);

    do
    {
        if (line[0] == 'T')
        {
            fscanf(fp1, "%s", line);
            for (i = 1, j = 0; i < 7; i++, j++)
                adr[j] = line[i];
            adr[j] = '\0';

            // String to Hex
            fp2 = fopen("temp.txt", "r+");
            fprintf(fp2, "%s", adr);
            rewind(fp2);
            fscanf(fp2, "%x", &hexadr);
            fclose(fp2);

            i = 9;
            while (line[i] != '\0')
            {
                printf("%x\t%c%c\n", (hexadr + start), line[i], line[i + 1]);
                hexadr++;
                i += 2;
            }
        }

    } while (!feof(fp1));
    fclose(fp1);
    return 0;
}

/*
3008    23
3009    2
300a    14
300b    20
300c    33
300d    48
300e    30
300f    39
3010    10
3011    20
3012    36
3013    42
3014    03
3015    34
3016    83
3017    03
3018    91
3019    02
301a    03
301b    29
301c    83
301d    00
301e    23
301f    00
3020    00
3021    28
3022    20
3023    30
3024    30
3025    20
3026    15
3027    29
3028    83
3029    00
302a    23
302b    00
302c    00
302d    28
302e    20
302f    30
3030    30
3031    20
3032    15
*/