 .model small

.stack 100h

.data 

.code
    ;HLT
    MOV SI, 1000H; initial offset
    
    MOV [SI],0x1F01;
    
    MOV AX, 0x1F01
    
    MOV [SI + 2], 0xA0EF
    
    MOV BX, 0xA0EF
    
    MOV [SI + 4], 0x7704
    
    MOV CX, 0x7704
    
    MOV [SI + 6], 0x34B0
    
    MOV DX, 0x34B0
    
    MOV [SI + 8], 0x2250
    
    MOV DI, 0x2250
    
    ADD AX,BX
    
    ADD AX, CX
    
    ADD AX, DX
    
    ADD AX, DI 
    
    MOV DX, AX
    
    MOV AX, 0CD1FH
    
    MOV DS, AX
    
    MOV [0003H],DX
        