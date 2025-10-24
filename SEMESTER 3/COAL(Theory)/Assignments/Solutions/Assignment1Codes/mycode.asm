.model small
 
 .stack 100h
 
 .data
 
 .code
 
 
               
 mov bx, 0x12C2              
 
 MOV CX, 0xFEED
 
 MOV DX, 0x2032
 
 
 mov si, 0x0024
 
 mov di, 0x0032
 
 mov bp, 0x0110
 
 MOV AX, 0xA1B9
 
 mov ds, AX
 
 MOV AX, 0x3C80
 
 mov ss, AX
 
 MOV AX, 0x1AB0
 
 mov es, AX
 
 MOV AX, 0xABCD    
 
 MOV [BX+SI], CX
 
 MOV SS:[BP+DI+0x0016], DX
 
 MOV AX, [BX+DI]
 
 MOV [BX+SI+9d], CX
 
 MOV DX, DS:[BP+SI+11BCH] 
 
 