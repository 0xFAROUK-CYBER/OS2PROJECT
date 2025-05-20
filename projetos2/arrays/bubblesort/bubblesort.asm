section .text
    global bubbleSort

; void bubbleSort(int* arr, int size)
; rdi = pointer to array
; rsi = size

bubbleSort:
    push rbp
    mov rbp, rsp

    mov rbx, rdi       ; rbx = arr pointer
    mov r8, rsi        ; r8 = size

outer_loop:
    mov rcx, 0         ; i = 0

check_outer:
    cmp rcx, r8
    jge end_outer      ; if i >= size, end

    mov rdx, 0         ; j = 0

inner_loop:
    mov r9, r8
    sub r9, rcx
    dec r9             ; r9 = size - i - 1
    cmp rdx, r9
    jge end_inner

    ; Compare arr[j] and arr[j+1]
    mov eax, [rbx + rdx*4]
    mov ecx, [rbx + rdx*4 + 4]

    cmp eax, ecx
    jle no_swap

    ; Swap
    mov [rbx + rdx*4], ecx
    mov [rbx + rdx*4 + 4], eax

no_swap:
    inc rdx
    jmp inner_loop

end_inner:
    inc rcx
    jmp check_outer

end_outer:
    pop rbp
    ret

