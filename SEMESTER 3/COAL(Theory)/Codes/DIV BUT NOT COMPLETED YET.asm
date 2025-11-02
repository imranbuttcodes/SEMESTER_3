;DIV TO DIVIDE WE DIVIDE WORD BY BYTE WORD/BYTE OR 16-BITS/8-BITS   

;THE WORD WILL BE AX AND THE BYTE WILL BE USER'S 8-BIT NUMBER

;THE REMAINDER(MODE) WILL BE STORE IN AH AND THE QUOTIENT WILL STORE IN AL 

;EXAMPLE# 1
MOV AX,5
MOV BL,2

DIV BL  

MOV AX,0X15FF
MOV BL,5
DIV BL

; ---------------------------------------------------------------------------
; PROGRAM: Custom Divide Error Handler (INT 0)
; PURPOSE: Demonstrates how to handle division errors by modifying IVT
; ---------------------------------------------------------------------------

.MODEL SMALL                    ; Memory model: 64KB code, 64KB data
.STACK 100H                     ; Allocate 256 bytes for stack

.DATA
    msg DB 'Division Error Occurred!$'  ; Error message ($ = string terminator)

.CODE

; ---------------------------------------------------------------------------
; PROCEDURE: MyDivErrorHandler
; PURPOSE: Custom interrupt handler for INT 0 (Divide Error)
; CALLED BY: CPU automatically when division error occurs
; NOTES: Must use IRET (not RET) to return from interrupt
; ---------------------------------------------------------------------------
MyDivErrorHandler PROC
    PUSH AX                     ; Save AX register (will be modified)
    PUSH DX                     ; Save DX register (will be modified)
    
    MOV AH, 09H                 ; DOS function 09H: Display string
    LEA DX, msg                 ; Load address of error message into DX
    INT 21H                     ; Call DOS interrupt to print message
    
    POP DX                      ; Restore DX register
    POP AX                      ; Restore AX register
    IRET                        ; Interrupt return (pops IP, CS, FLAGS)
MyDivErrorHandler ENDP

; ---------------------------------------------------------------------------
; PROCEDURE: MAIN
; PURPOSE: Main program - modifies IVT and tests divide error
; ---------------------------------------------------------------------------
MAIN PROC
    ; --- Initialize Data Segment ---
    MOV AX, @DATA               ; Get segment address of data segment
    MOV DS, AX                  ; Set DS to point to data segment
    
    ; -----------------------------------------------------------------------
    ; SECTION: Modify Interrupt Vector Table (IVT)
    ; PURPOSE: Replace default INT 0 handler with our custom handler
    ; -----------------------------------------------------------------------
    
    CLI                         ; Clear Interrupt flag (disable interrupts)
                                ; CRITICAL: Prevent interrupts during IVT modification
    
    PUSH DS                     ; Save current DS (data segment)
    
    ; --- Point DS to IVT (located at physical address 0x00000) ---
    MOV AX, 0000H               ; AX = 0000H (segment address of IVT)
    MOV DS, AX                  ; DS = 0000H, now DS:xxxx points to IVT
    
    ; --- Store OFFSET of handler (first 2 bytes of INT 0 vector) ---
    MOV AX, OFFSET MyDivErrorHandler  ; Get offset address of our handler
    MOV [0000H], AX             ; Store at 0000:0000 (bytes 0-1 of IVT)
                                ; This is the IP (instruction pointer) part
    
    ; --- Store SEGMENT of handler (next 2 bytes of INT 0 vector) ---
    MOV AX, SEG MyDivErrorHandler     ; Get segment address of our handler
    MOV [0002H], AX             ; Store at 0000:0002 (bytes 2-3 of IVT)
                                ; This is the CS (code segment) part
    
    ; --- IVT Structure at 0000:0000 ---
    ; [0000H] = Offset Low Byte
    ; [0001H] = Offset High Byte
    ; [0002H] = Segment Low Byte
    ; [0003H] = Segment High Byte
    
    POP DS                      ; Restore original DS (data segment)
    STI                         ; Set Interrupt flag (re-enable interrupts)
    
    ; -----------------------------------------------------------------------
    ; SECTION: Test Division by Zero
    ; PURPOSE: Trigger INT 0 to test our custom handler
    ; -----------------------------------------------------------------------
    
    MOV AX, 0064H               ; AX = 100 decimal (dividend)
    MOV BL, 00H                 ; BL = 0 (divisor)
    DIV BL                      ; ? DIVIDE BY ZERO!
                                ; CPU automatically triggers INT 0
                                ; Jumps to address stored at 0000:0000
                                ; Executes MyDivErrorHandler
                                ; Prints "Division Error Occurred!"
    
    ; --- Exit Program ---
    MOV AH, 4CH                 ; DOS function 4CH: Terminate program
    INT 21H                     ; Call DOS interrupt to exit
MAIN ENDP

END MAIN                        ; End of program, entry point is MAIN

; ---------------------------------------------------------------------------
; KEY CONCEPTS:
; ---------------------------------------------------------------------------
; 
; 1. IVT (Interrupt Vector Table):
;    - Located at physical address 0x00000
;    - Each interrupt has 4-byte entry (2 bytes offset + 2 bytes segment)
;    - INT 0 entry is at bytes 0-3
;
; 2. CLI/STI:
;    - CLI = Clear Interrupts (disable)
;    - STI = Set Interrupts (enable)
;    - Used to prevent interrupts during critical operations
;
; 3. IRET vs RET:
;    - RET: Normal return (pops IP only)
;    - IRET: Interrupt return (pops IP, CS, and FLAGS)
;
; 4. Division Error Triggers:
;    - Division by zero
;    - Quotient too large for destination register
;
; 5. Physical Address Calculation:
;    - Physical = (Segment × 10H) + Offset
;    - 0000:0000 = (0000H × 10H) + 0000H = 0x00000
;
; ---------------------------------------------------------------------------