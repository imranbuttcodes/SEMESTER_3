 .MODEL SMALL
 
 .DATA
 
 ARR1 DB 1,2,3,4       
      DB 5,6,7,8
      DB 9,10,11,12
 
 ARR2 DB 1,2,3,4       
      DB 5,6,7,8
      DB 9,10,11,12
 

ARR3 DB 4 DUP(1)

     DB 4 DUP(1)
     
     DB 4 DUP(1) 
     
       

.CODE 

     MOV AX,@DATA
     
     MOV DS,AX   
     
     MOV SI,0
     
     MOV CX,12 
     
     L1:
        MOV DL,[ARR1 + SI]
        
        ADD DL,[ARR2 + SI]
        
        MOV [ARR3 + SI],DL
        
        INC SI
        
     LOOP L1
        
        
        
     

.EXIT