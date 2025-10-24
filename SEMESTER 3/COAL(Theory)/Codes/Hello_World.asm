.model small
.stack 100h

.data 

message db "Hello", 0dh,0Ah, "World$"

.code

main proc
    
    mov ax,@data
    mov ds,ax
    mov ah,09h
    lea dx,message
    
    int 21h
    
    mov ah,4ch
    int 21h
main endp
end main