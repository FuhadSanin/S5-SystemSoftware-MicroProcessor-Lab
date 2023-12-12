#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fint, *fop, *fsym, *flen;
    int i, len, start;
    char label[20], opcode[20], operand[20], adr[20];
    char code[20], mnemonic[20];
    char symbol[20], locctr[20];

    fint = fopen("intermediate.txt", "r");
    fop = fopen("optab.txt", "r");
    fsym = fopen("symtab.txt", "r");
    flen = fopen("length.txt", "r");

    fscanf(fint, "\t%s\t%s\t%s", label, opcode, operand);
    if (strcmp("START", opcode) == 0)
    {
        start = atoi(operand);
        fscanf(flen, "%d", &len);
    }
    printf("H^%s^00%s^00%d\n", label, operand, start + len);
    printf("T^00%s^", operand);

    fscanf(fint, "%s\t%s\t%s\t%s", adr, label, opcode, operand);
    while (strcmp("END", opcode) != 0)
    {
        fscanf(fop, "%s\t%s", code, mnemonic);
        while (!feof(fop))
        {
            if (strcmp(opcode, code) == 0)
            {
                fclose(fop);
                fscanf(fsym, "%s\t%s", symbol, locctr);
                while (!feof(fsym))
                {
                    if (strcmp(operand, symbol) == 0)
                    {
                        printf("%s%s^", locctr, mnemonic);
                        break;
                    }
                    else
                    {
                        fscanf(fsym, "%s\t%s", symbol, locctr);
                    }
                }
                break;
            }
            else
            {
                fscanf(fop, "%s\t%s", code, mnemonic);
            }
        }
        if (strcmp("WORD", opcode) == 0)
        {
            printf("0000%s^", operand);
        }
        else if (strcmp("BYTE", opcode) == 0)
        {
            len = strlen(operand);
            for (i = 2; i < len; i++)
            {
                printf("%d", operand[i]);
            }
            printf("^");
        }
        fop = fopen("optab.txt", "r");
        fscanf(fint, "%s\t%s\t%s\t%s", adr, label, opcode, operand);
        fseek(fop, SEEK_SET, 0);
    }
    printf("\nE^00%d\n", start);
    fclose(fint);
    fclose(fop);
    fclose(fsym);
    fclose(flen);

    return 0;
}