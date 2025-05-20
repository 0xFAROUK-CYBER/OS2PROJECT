section .note.GNU-stack noexec
section .text
global sum_of_digit   ; Export symbol for linking

sum_of_digit:
    push rbx            ; Save RBX
    mov rax, rdi        ; Get first argument (n)
    mov rcx, 10         ; Divisor for base-10 digits
    xor rbx, rbx        ; Clear sum (result)

.loop_sum:
    test rax, rax       ; Check if n == 0
    jz .fin_loop_sum_digit
    xor rdx, rdx        ; Clear upper 64 bits of dividend (rdx:rax)
    div rcx             ; rax = quotient, rdx = remainder (digit)
    add rbx, rdx        ; Add digit to sum
    jmp .loop_sum

.fin_loop_sum_digit:
    mov rax, rbx        ; Return sum in rax
    pop rbx             ; Restore RBX
    ret

