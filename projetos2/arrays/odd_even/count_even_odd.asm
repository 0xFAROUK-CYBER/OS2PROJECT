section .note.GNU-stack noexec
section .text
    global countEvenOdd

countEvenOdd:
    ; Arguments:
    ; rdi = pointer to int array
    ; rsi = size (number of elements)
    ; rdx = pointer to int evenCount
    ; rcx = pointer to int oddCount

    xor eax, eax          ; eax = evenCount = 0
    xor ebx, ebx          ; ebx = oddCount = 0

    test rsi, rsi
    jz done               ; if size == 0, done

    mov r8, rdi           ; r8 = current pointer to array start
    mov r9, rsi           ; r9 = size (loop counter)

.loop:
    mov edi, [r8]         ; load current int
    test edi, 1           ; test if LSB is 1 (odd check)
    jnz .odd
    inc eax               ; evenCount++
    jmp .next

.odd:
    inc ebx               ; oddCount++

.next:
    add r8, 4             ; move pointer to next int
    dec r9
    jnz .loop

done:
    mov rdi, rdx          ; pointer to evenCount
    mov [rdi], eax        ; store evenCount

    mov rdi, rcx          ; pointer to oddCount
    mov [rdi], ebx        ; store oddCount

    ret

