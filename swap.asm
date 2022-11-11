main:
li $t0, 0 # initializing i=0
li $a2, 3
la $a0, array
la $a1, permutations
li $t1, 1 # initialize one
j Loop


Loop:
slt $t2, $t0, $a2 # setting i < length
beq $t2, $t1, Loop2 # go to loop 2 if i < length
j Test


Loop2:
sll $t3, $t0, 2 # multiply i by 4
add $v0, $t3, $a0  # find index
lw $v1, 0($v0) # put array[i] into register v1
add $t5, $t3, $a1  # find index in permutations
lw $t6, 0($t5) # put permutations[i] into register t6
sll $t3, $t6, 2 # multiply permutations[i] by 4
add $t4, $t3, $a0  # find index in array[permutations[i]]
lw $t7, 0($t4) # put array[permutations[i]] into register t7
sw $v1, 0($t4) # put array[i] in array[permutations[i]]
sw $t7, 0($v0) # put array[permutations[i]] in array[i]
addi $t0, $t0, 1 # increment i
j Loop # go to loop

Test:
lw $t9, 8($a0)
jr $ra

.data
array: .word 5 , 10 , 15
permutations: .word 0, 2, 1
