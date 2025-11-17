.MODEL SMALL  


.DATA
      

ARR DW 1,9,2,8,3,20,16,5,7,19,6,4,11,14,17,13,12,10,15,18      

A DB 1,2,3,4,5

B DB 1,2,3,4,5

C DB 5 DUP(?)

SIZE DB 5
      

.CODE
       
MOV AX,@DATA

MOV DS,AX       
                    
;0x1F540398                    

;0xC0A1F02E

;MOV AX,0X0398                    

;MOV DX,0XF02E

;MOV BX,0X1F54

;MOV CX,0XC0A1

;ADD AX,DX

;ADC BX,CX  

;MOV SI ,0

;MOV [0X1010 + SI],AX  

;ADD SI,2

;MOV [0X1010+SI],BX



;MOV AX,0X2113

;OR AX,0X2340

;AND AX,0XABFF

;MOV DX,0XFF12

;NOT DX

;XOR DX,AX
 


 
;MOV AL,80H

;ADD AL,80H 

   
;MOV AX,@DATA

;MOV DS,AX    

;MOV AL,[NUM]

;MOV SI,0

;MOV DI,0   


;MOV CX,20

;L1:

;    MOV DL,[ARR + SI]
    
;    CMP AL,DL
    
;;    JZ INC_COUNT
    
;    INC SI
    
;    LOOP L1    
            
            
            
;.EXIT            
    
;INC_COUNT:

  ;  INC DI
    
 ;   INC SI
          
;    DEC CX
          
;    JMP L1    



;MOV CX,19;SIZE -1

;OUTER:

;MOV SI,0

;MOV DI,CX

;INNER:

;MOV AX,[ARR + SI] 

;MOV DX,[ARR + SI + 2] 

;CMP AX,DX

;JNGE NO_SWAP

;    MOV [ARR + SI],DX
;   
;    MOV [ARR + SI + 2],AX
               
               
    
;NO_SWAP:

;ADD SI,2

;DEC DI

;JNZ INNER  


;loop OUTER


;STACK


;MOV AX,0X1234 

;MOV BX,0X5678

;PUSH AX 

;PUSH BX

;MOV AX,0

;MOV BX,0        

;MOV BP,SP

;MOV [BP],0X5555

;MOV BX,[BP]   
   
;MOV AX,[BP + 2]        

;POP BX

;POP AX   
      
      
;MOV AX,1

;MOV BX,2  


;CALL ADD_NUM

;JMP EXIT_PROG    

;ADD_NUM PROC
    
;    ADD AX,BX
    
;    RET
    
;ADD_NUM ENDP


;EXIT_PROG:   
   

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
    

