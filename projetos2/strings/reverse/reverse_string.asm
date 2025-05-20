section .note.GNU-stack noexec
section .text
    global reverseString

reverseString:
    ; Input:
    ; rdi = pointer to null-terminated string

    mov rsi, rdi          ; save start pointer

    ; Find string length (exclude null terminator)
    xor rcx, rcx          ; length counter = 0

.find_end:
    mov al, [rdi + rcx]
    test al, al
    jz .found_length
    inc rcx
    jmp .find_end

.found_length:
    dec rcx               ; rcx = last char index (length -1)

    ; rsi = start pointer
    ; rdi = start pointer (will be used as moving pointer)
    ; rcx = last char index

    mov rdx, 0            ; rdx = front index

.swap_loop:
    cmp rdx, rcx
    jge .done             ; done if front >= back

    ; swap characters at rsi+rdx and rsi+rcx
    mov al, [rsi + rdx]
    mov bl, [rsi + rcx]
    mov [rsi + rdx], bl
    mov [rsi + rcx], al

    inc rdx
    dec rcx
    jmp .swap_loop

.done:
    ret

