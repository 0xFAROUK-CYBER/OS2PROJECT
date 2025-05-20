section .text
    global stringLength

; int stringLength(char* str)
; Input:  rdi = pointer to null-terminated string
; Output: eax = length (int)

stringLength:
    push rbp
    mov rbp, rsp

    xor rcx, rcx          ; counter = 0

.loop:
    mov al, byte [rdi + rcx] ; load character at str[rcx]
    cmp al, 0              ; check for null terminator
    je .done
    inc rcx
    jmp .loop

.done:
    mov eax, ecx           ; move result to eax (return value)
    pop rbp
    ret

