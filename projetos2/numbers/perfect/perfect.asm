section .text
    global isPerfect

isPerfect:
    push rbp
    mov rbp, rsp

    mov eax, edi        ; eax = input number
    cmp eax, 1
    jle .not_perfect

    mov ecx, 2          ; divisor = 2
    mov ebx, eax        ; store original number
    shr ebx, 1          ; limit = num / 2
    mov edx, 1          ; sum = 1

.loop:
    cmp ecx, ebx
    jg .done

    mov esi, eax        ; num
    xor edx, edx
    div ecx             ; divide num by ecx
    cmp edx, 0
    jne .skip

    add edx, ecx        ; add divisor to sum

.skip:
    inc ecx
    jmp .loop

.done:
    mov eax, edx
    cmp eax, edi
    sete al
    movzx eax, al
    pop rbp
    ret

.not_perfect:
    xor eax, eax
    pop rbp
    ret

