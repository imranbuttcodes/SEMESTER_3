.MODEL SMALL

.DATA

ARR DW 1,4,6,2,9,54,10,12,34,55,6,3,2,8,99,54,21,66,7,8  


SIZE DW 20

HELPER_SIZE DW 0                        

.CODE 

MOV AX,@DATA

MOV DS,AX
 



MOV CX,19; SIZE - 1 (OUTER LOOP) 



BUBBLE_SORT_OUTER:
    MOV SI,0
    
    MOV DI,CX                      
    
    
    BUBBLE_SORT_INNER: 
        
        
        MOV AX,[ARR + SI] 
        
        MOV DX,[ARR + SI + 2]
    
        CMP AX,DX
                            
                            
        JNG NO_SWAP             
        MOV [ARR + SI],DX
        MOV [ARR + SI + 2],AX       
        

NO_SWAP:

ADD SI,2
DEC DI
JNZ BUBBLE_SORT_INNER

LOOP BUBBLE_SORT_OUTER


.EXIT
