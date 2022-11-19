
.data

JUMP_TABLE: .word case0, case1, case2, case3, case4, case5, case6

chars: .byte 10

enum: .word 10

sunday: .asciiz "Sunday"

monday: .asciiz "Monday"

tuesday: .asciiz "Tuesday"

wednesday: .asciiz "Wednesday"

Thursday: .asciiz "Thursday"

friday: .asciiz "Friday"

saturday: .asciiz "Saturday"

error: .word 0

.text
main:

la $a0, JUMP_TABLE
la $a1, chars
la $a2, enum
li $t3, -1
la $t6, error
li $t7, 1
sll $t1, $a2, 2
slt $t2, $t3, $t1
bne $t2, $zero, QuickCheck

CheckReturn:
beqz $t2, Invalid
add $a0, $a0, $a1
lw $a0, 0($a0)
jr $a0

QuickCheck:
slti $t2, $t1, 25
j CheckReturn


case0:
la $t4, sunday
j Copy

case1:
la $t4, monday
j Copy

case2:
la $t4, tuesday
j Copy

case3:
la $t4, wednesday
j Copy


case4:
la $t4, thursday
j Copy

case5:
la $t4, friday
j Copy

case6:
la $t4, saturday
j Copy

Copy:
lb $t5, 0($t4)
beq $t5, $zero, Exit
sb $t5, 0($a1)
addi $a1, $a1, 1
addi $t4, $t4, 1
j Copy

Invalid:
sw $t7, 0($t6)
move $v0, $t7
jr $ra

Exit:
sb $zero, 0($a1)
jr $ra



