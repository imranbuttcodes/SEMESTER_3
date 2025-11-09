;LAB 06 TASK # 1

.MODEL SMALL

.DATA

ARR DB 1,2,3,4,5,6,2,2,2,2,5,6,6,7,8,8,8,9,2,2     

NUM_OCCURED_TIMES DB 0

.CODE

MOV AX,@DATA

MOV DS,AX    

MOV CX,20   

MOV AL,2; NUMBER WHOSE NUMBER OF OCCURENCES WE WANNA FIND

MOV SI,0
          
MOV AH, 0          
      
           
MY_LOOP:

  CMP AL,[ARR + SI]       

  JZ COUNT_FREQ           
  
  ADD SI,1
  
  LOOP MY_LOOP           
  

MOV AL,[NUM_OCCURED_TIMES] 
  
.EXIT  
  

           
COUNT_FREQ:


    ADD [NUM_OCCURED_TIMES],1  
    
    ADD SI,1 
    
    JMP MY_LOOP 
               
    
    
   