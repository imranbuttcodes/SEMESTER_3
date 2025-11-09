.MODEL SMALL

.DATA 

A DB 1,2,3,4
  DB 5,6,7,8
  DB 9,10,11,12
  
B DB 1,2,3
  DB 4,5,6
  DB 7,8,9
  DB 10,11,12
  
C DB ?     

SUM DB 0

I DB 0

J DB 0

K DB 0

A_ROWS DB 3

A_COLS DB 4

B_ROWS DB 4

B_COLS DB 3

          

.CODE

MOV AX,@DATA

MOV DS,AX
      
MOV CH,0
      
MOV CL, [A_ROWS]   

ADDRESS:

    


L1:
         
    MOV CL,[B_COLS]
            
    L2:
        
        MOV [SUM],0
        
        MOV CL,[A_COLS]
        
        L3:
        
            
                      