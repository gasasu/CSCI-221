
main:
li $v0, 0
j loop

loop:
lh $t0, 0($a0)
add $v0, $v0, $t0
lw $a0, 4($a0)
beq $a0, $zero, Exit
j loop
Exit:
jr $ra
