main:
addi $a0, $zero, 7
addi $v0, $zero, 0 # ans = 0
addi $t0, $zero, 3  # c = 3
slt $t2, $a0, $t0 # set a < 3
addi $t1, $zero, 2 # set b = 2
addi $a1, $zero, 1
addi $a2, $zero, 1
beq $t2, $zero, Loop # go to loop if a>3
addi $v0, $zero, 1

Loop:
addi $t1, $t1, 1
slt $t3, $a0, $t1
beq $t3, $zero, Loop2
j Exit


Loop2:
add $v0, $a1, $a2
add $a2, $a1, $zero
add $a1, $v0, $zero
j Loop

Exit:
jr $ra
