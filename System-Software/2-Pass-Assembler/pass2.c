#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fint, *ftab, *flen, *fsym;
    int op1[10], textlen, textlen1, i, j = 0, len;
    char add[5], locctr[5], mnemonic[5], start[10], temp[30], line[20], label[20], opcode[10], operand[10], symbol[10], code[10];
    fint = fopen("intermediate.txt", "r");
    flen = fopen("length.txt", "r");
    ftab = fopen("optab.txt", "r");
    fsym = fopen("symtab.txt", "r");
    fscanf(fint, "%s%s%s%s", add, label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        strcpy(start, operand);
        fscanf(flen, "%d", &len);
    }
    printf("H^%s^%s^%d\nT^00%s^", label, start, len, start);
    fscanf(fint, "%s%s%s%s", add, label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        fscanf(ftab, "%s%s", code, mnemonic);
        while (!feof(ftab))
        {
            if (strcmp(opcode, code) == 0)
            {
                fclose(ftab);
                fscanf(fsym, "%s%s", locctr, symbol);
                while (!feof(fsym))
                {
                    if (strcmp(operand, symbol) == 0)
                    {
                        printf("%s%s^", mnemonic, locctr);
                        break;
                    }
                    else
                    {
                        fscanf(fsym, "%s%s", locctr, symbol);
                    }
                }
                break;
            }
            else
            {
                fscanf(ftab, "%s%s", code, mnemonic);
            }
        }
        
        if (strcmp(opcode, "WORD") == 0)
        {
            printf("0000%s^", operand);
        }
        else if (strcmp(operand, "BYTE") == 0)
        {
            len = strlen(operand);
            for (i = 2; i < len; i++)
            {
                printf("%d", operand[i]);
            }
            printf("^");
        }
        
        fscanf(fint, "%s%s%s%s", add, label, opcode, operand);
        ftab = fopen("optab.txt", "r");
        fseek(ftab, SEEK_SET, 0);
    }
    printf("\nE^00%s", start);
    fclose(fint);
    fclose(ftab);
    fclose(fsym);
    fclose(flen);
}