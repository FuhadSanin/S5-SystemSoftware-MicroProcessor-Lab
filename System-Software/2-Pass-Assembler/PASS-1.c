#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne(char[], char[], char[], char[], char[]);
void display();
int main()
{
    char label[20], opcode[20], operand[20]; // INPUT.TXT
    char code[20], mnemonic[20];             // OPTAB.TXT
    passOne(label, opcode, operand, code, mnemonic);
}
void passOne(char label[], char opcode[], char operand[], char code[], char mnemonic[])
{
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");

    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    // STARTING LINE
    if (strcmp("START", opcode) == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }
    // REST OF LINE
    while (strcmp("END", opcode) != 0)
    {
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        // SYMTAB.TXT (WITHOUT **)
        if (strcmp("**", label) != 0)
        {
            fprintf(fp3, "%s\t%d\n", label, locctr);
        }
        fscanf(fp2, "%s\t%s", code, mnemonic);
        // OPTAB.TXT
        while (strcmp(code, "END") != 0)
        {
            if (strcmp(code, opcode) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }
        // OPTAB.TXT
        if (strcmp(opcode, "WORD") == 0)
        {
            locctr += 3;
        }
        // RESW -> add 3*operand to locctr
        else if (strcmp(opcode, "RESW") == 0)
        {
            locctr += (3 * (atoi(operand))); // convert operand to integer and multiply with 3
        }
        // BYTE -> add 1 to locctr
        else if (strcmp(opcode, "BYTE") == 0)
        {
            ++locctr;
        }
        // RESB -> add operand to locctr
        else if (strcmp(opcode, "RESB") == 0)
        {
            locctr += atoi(operand);
        }
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);

    display();
}

void display()
{
    char str;
    FILE *fp1, *fp2, *fp3;

    // 1. Input Table
    printf("\nThe contents of Input Table :\n\n");
    fp1 = fopen("input.txt", "r");
    str = fgetc(fp1);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp1);
    }
    fclose(fp1);

    // 2. Output Table
    printf("\n\nThe contents of Output Table :\n\n");
    fp2 = fopen("intermediate.txt", "r");
    str = fgetc(fp2);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp2);
    }
    fclose(fp2);

    // 3. Symtable
    printf("\n\nThe contents of Symbol Table :\n\n");
    fp3 = fopen("symtab.txt", "r");
    str = fgetc(fp3);
    while (str != EOF)
    {
        printf("%c", str);
        str = fgetc(fp3);
    }
    fclose(fp3);
}