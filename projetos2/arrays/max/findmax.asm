section .text
    global findMax

; int findMax(int* arr, int size)
; rdi = pointer to array
; rsi = size

findMax:
    push rbp
    mov rbp, rsp

    mov rbx, rdi        ; rbx = base address of array
    mov rcx, 1          ; index = 1
    mov eax, [rbx]      ; eax = max = arr[0]

.loop:
    cmp rcx, rsi
    jge .done           ; if index >= size, exit loop

    mov edx, [rbx + rcx*4] ; edx = arr[index]
    cmp edx, eax
    jle .next           ; if arr[i] <= max, skip
    mov eax, edx        ; update max

.next:
    inc rcx
    jmp .loop

.done:
    pop rbp
    ret

