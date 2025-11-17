.MODEL SMALL

.DATA

A DB "MADAM"

LAST_IDX DB 4



.CODE

MOV AX,@DATA

MOV DS,AX

MOV AL,[LAST_IDX] 

MOV AH,0

MOV CX,AX 

MOV BX,OFFSET A

PUSH BX

MOV BL,[LAST_IDX]          
MOV BH,0

PUSH BX        

CALL IS_PALINDROME

IS_PALINDROME PROC
   
       PUSH BP
       
       MOV BP,SP
       
       ;MOV BX,[BP + 4]
       
    
       
       MOV CH,0
       MOV SI,0
                            
        MOV AH,0  
        
        MOV DI,1      
        
       MOV BX,[BP + 6]                    
       L1:
        
          
          ;MOV BX,[BP + 6]
          
          MOV AL,[BX + SI]
          
          PUSH SI
          
          MOV SI,CX      
          MOV DL,[BX + SI]
          
          MOV DH,0           
          
          CMP AX,DX
           
          JNZ STORE_RESULT
          
          POP SI
          
          INC SI
          
          CMP SI,CX
          
          JGE EXIT_PROGRAM
          
       LOOP L1          
       
        POP BP
       
        RET
        
 IS_PALINDROME ENDP       
    

STORE_RESULT:

MOV DI, 0     

POP BP

JMP EXIT_PROGRAM



EXIT_PROGRAM:

.EXIT


.EXIT
    