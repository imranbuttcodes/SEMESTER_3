 .MODEL SMALL
 
 .STACK 100H
 
 .DATA
 
 .CODE
 PROC MAIN        
    
    MOV AX, 0X1442
    MOV BX, 0X7235
    MOV CX, 0XA1B2
    MOV DX, 0X4482   
    ;Expression DX = BX + AX + DL+ DX
    
    ;ADD AX, BX
    
    ;ADD AX, DX
    
    ;MOV DH, 0H
    
    ;ADD AX, DX
    
    ;MOV DX, AX
                
    ;EXPRESSION: CX = AX + BX + CX + DX + AL + CH - CL + BH - DL                
  

;EXPRESSION: CX = AX + BX + CX + DX + AL + CH - CL + BH - DL                
    MOV SI, AX
    ADD AX,BX

ADD AX,CX

    ADD AX,DX 
    ;CALCULATING CH-CL

    SUB CH,CL

    MOV CL,CH

    MOV CH, 0H  
    ADD AX,CX
    ;CALULATING AL FROM
    MOV CX,SI
    MOV CH,0H
    ADD AX,CX       
 ;(BH = BH-DL)   
    SUB BH,DL

    MOV BL,BH

    MOV BH,0H

    ADD AX,BX

    MOV CX,AX
 ENDP MAIN
 ENDP    
 .EXIT