DATA SEGMENT
    MSG1 DB 0AH,0DH,"ENTER THE STRING : $"
    MSG2 DB 0AH,0DH,"VOWEL COUNT : $"
    VOWEL DB 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', '$'
    STRING DB 09H DUP("$")
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:  MOV AX,DATA
            MOV DS, AX

            MOV BL,00H;NO OF VOWELS

            LEA DX,MSG1
            MOV AH,09H
            INT 21H

            ;STRING READw
            LEA DX,STRING
            MOV AH,0AH
            INT 21H
            MOV SI,DX

            LEA DX,MSG2
            MOV AH,09H
            INT 21H
    ;DI->VOWEL AND SI->STRING
    SCAN:   LEA DI,VOWEL;VOWEL READ
            MOV CX,0AH;10 VALUES IN VOWEL SO THE LOOP WORK 10 TIMES
            MOV AL,[SI]

    COUNT:  CMP AL,[DI]
            JZ FOUND
            INC DI
            LOOP COUNT
            JMP NEXT;WHEN LOOP EXIT AFTER CX = 10 JMP INTO NEXT

    FOUND:  INC BL
    NEXT:   INC SI
            CMP STRING[SI],0DH;INDICATE THE END OF STRING
            JNZ SCAN

            MOV DL,BL
            ADD DL,30H;INT TO ASCII CONVERSION
            MOV AH,02H;TO DISPLAY THE COUNT
            INT 21H

            MOV AH,4CH
            INT 21H
CODE ENDS
END START