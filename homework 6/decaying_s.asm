; length 16_t $a1
; values 16t $a0
; decay 16t $a2
; rest 32t $v0

 addi $a1, $a1, -1
 li $t1, -1
 li $v0,0

 Loop:
 slt $t2, $t1, $a1  ; -1 < length
 beq $t2, $zero, Exit ; exit if True
 sll $t3, $a1, 2    ; multiply length by 4
 add $t4, $t3, $a0  ; get right address
 lh $t5, 0($t4)     ; load 16 bit value
 div $v0, $a2       ; divide
 mflo $t6           ; store lowest 16 bit
 add $v0, $t6, $t5  ; add result to rest
 addi $a1, $a1, -1  ; decrement counter
 j Loop             ; go back to loop

 Exit:
 jr $ra
