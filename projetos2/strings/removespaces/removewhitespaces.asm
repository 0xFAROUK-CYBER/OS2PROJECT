section .text
    global removeWhitespaces

; void removeWhitespaces(char* str)
; Input: rdi = pointer to string

removeWhitespaces:
    push rbp
    mov rbp, rsp

    mov rsi, rdi      ; rsi = write pointer
    mov rdx, rdi      ; rdx = read pointer

.loop:
    mov al, byte [rdx]
    cmp al, 0
    je .done

    cmp al, ' '
    je .skip

    mov [rsi], al
    inc rsi

.skip:
    inc rdx
    jmp .loop

.done:
    mov byte [rsi], 0 ; null terminate
    pop rbp
    ret

