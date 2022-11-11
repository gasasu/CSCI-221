
main:
la $a0, arr # arr = [4,7,9,1,15]
li $a1, 5 # length = 5
li $a2, -1 # i = 0
li $s0,0 # # small = 0
li $s1, 0 # large = 0
li $s2, 0 # mid1 = 0
li $s3, 0 # mid2 = 0
li $t0, 2 # first = 20
li $t1, 7  # second = 28
li $t2, 10 # third = 30
j Loop

Loop:
addi $a2, $a2, 1 # count += 1
slt $t4, $a2, $a1 # if count < n
bne $t4, $zero, First # go to loop1
j Exit

First:
sll $a3 , $a2, 2 # mult = 4*count
addu $t6, $a0, $a3 # array[i] access
lw $v0, 0($t6)  # v0 = array[i]
slt $t5, $v0, $t0 # array[i] < first
beq $t5, $zero, Second # if True, go to loop2
addi $s0, $s0, 1 # else increase smallest
j Loop # go back to loop

Second:
slt $t5, $v0, $t1 # array[i] < second
beq $t5, $zero, Loop3 # if True, go to loop2
addi $s2, $s2, 1
j Loop # go back to loop

Loop3:
slt $t5, $v0, $t2 # array[i] < third
beq $t5, $zero, Loop4 # if True, go to loop4
addi $s3, $s3, 1
j Loop # go back to loop

Loop4:
addi $s1, $s1, 1 # increment largest count
j Loop


Exit:
jr $ra

.data
arr: .word 4 , 7 , 9 , 1 , 15

