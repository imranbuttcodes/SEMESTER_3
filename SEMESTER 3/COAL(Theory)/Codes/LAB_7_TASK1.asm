.MODEL SMALL

.DATA

A DB 1,2,3,4,5

B DB 1,2,3,4,5

C DB 5 DUP(?)

SIZE DB 5

.CODE

MOV AX,@DATA

MOV DS,AX

MOV BX,OFFSET SIZE   

PUSH BX 

MOV BX,OFFSET A

PUSH BX

MOV BX,OFFSET B

PUSH BX       

MOV BX,OFFSET C

PUSH BX

PUSH BP 
 
CALL SUM   


.EXIT

SUM PROC
          
 
    MOV BP,SP        
    
    MOV BL,[BP + 10]
    
    MOV BH,0
    
    
    MOV AX,[BX]
    
    MOV CX,AX
    
    
    MOV AH,0
    MOV BH,0
    MOV CH,0
    
    MOV DH,0
                           
                           
    MOV SI,0                       
    L1:
    
        MOV BL,[BP + 8]
        
        MOV DL,[BX+SI]
        
        MOV BL,[BP + 6]
        
        MOV AL,[BX + SI]
    
        ADD AL,DL
        
        MOV BL,[BP + 4]
        
        MOV [BX + SI],AL   
        
        INC SI
        
    LOOP L1    
    
    POP BP    
      
    RET
    
SUM ENDP
.EXIT
    