.MODEL SMALL

.DATA


2D_ARR DB 1,2,3
    
       DB 4,5,6  
       
       DB 7,8,9
       
       
T_ARR DB 3 DUP(?)

      DB 3 DUP(?)
      
      DB 3 DUP(?) 
      
      
      
CMP_ROW DB 3

R_ADD DW 3      

.CODE                      

MAIN PROC
    
 MOV AX,@DATA
 
 MOV DS,AX
 
 MOV SI,0
 
 MOV DI,0 
 
 
PUSH DI  

MOV DL,0 
 
 MOV CX,9
 
 L1:
    MOV AL,[2D_ARR + SI]
    
    MOV [T_ARR + DI],AL   
    
    ADD DI,[R_ADD]
 
    INC SI
    
    INC DL
    
    CMP CX,1
    
    JZ EXIT_
    
    CMP DL,[CMP_ROW] 
    
    
    JZ UPDATE_DI 
    
    
    LOOP L1
    
    
    
;JMP L1:
       


EXIT_:

.EXIT
  
                           
                           
                           
 
    
UPDATE_Di:
    
        

POP DI

ADD DI,1

MOV DL,0

PUSH DI 

DEC CX
  
JMP L1
                                                    