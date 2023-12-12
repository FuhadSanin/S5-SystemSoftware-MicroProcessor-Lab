DATA SEGMENT
    MSG1 DB 0AH,0DH, "ENTER THE STRING : $"
    MSG2 DB 0AH,0DH, "PALINDROME $"
    MSG3 DB 0AH,0DH,"NOT PALINDROME $"
    n DB 09H DUP(?)
DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE,DS:DATA
        START:  MOV AX,DATA
                MOV DS,AX
                ;Two pointers
                MOV SI,OFFSET n
                MOV DI,OFFSET n
                ;Print msg1
                LEA DX,MSG1
                MOV AH,09H
                INT 21H
                MOV CL,00H
        ;Read the string
        SCAN:   MOV AH,01H
                INT 21H
                CMP AL,0DH
                JZ CHECK
                MOV [SI],AL
                INC CL
                INC SI
                JMP SCAN
        ;Check PALINDROME or NOT PALINDROME
        CHECK:  DEC SI
                MOV BL,[SI]
                CMP [DI],BL
                JNZ NOTPAL
                INC DI
                DEC CL
                JNZ CHECK
        PAL:    LEA DX,MSG2
                MOV AH,09H
                INT 21H
                JMP FINISH
        NOTPAL: LEA DX,MSG3
                MOV AH,09H
                INT 21H
        FINISH: MOV AH,4CH
                INT 21H
                
        CODE ENDS
END START