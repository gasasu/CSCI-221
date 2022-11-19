;Write a MIPS assembly function that takes as input pointers to two lists of 32 bit integers,
;a pointer to a list of 64 bit integers and the length of those lists, which is assumed to be the same.
;(All lists have the same length.) Each element in the third list should be set to the product of the
;corresponding elements in the first two lists. In code form, this means:
;for (int i=0; i<length; i++){
;array3[i] = array1[i] * array2[i];
;}
;For full credit, use your function from the previous part.
; a0 - 64 bit list, a1 - 32 bit list, a2 - 32 bit list, a3 = length

li $t0, 0   ; counter = 0
mult:
slt $t1, $t0, $a3 ; counter < length
bne $t1, $zero, Mult ; mult if True
jr $ra

Mult:
sll $t2, $t0, 2 ; multiply counter by 4
add $t3, $t2, $a1 ; list1[counter]
lw $a0, 0($t3) ;access list1[counter]
add $t3, $t2, $a2 ; list2[counter]
lw $a1, 0($t3); acess list2[counter]

addiu $sp, $sp, -32 # push frame
sw $ra, 28($sp) 	  # Store $ra
sw $fp, 24($sp) 	  # Store $fp
addiu $fp, $sp, 28  # Set new $fp

jal multiplication 		  # call bar
lw $fp, 24($sp) 	  # Load $fp
lw $ra, 28($sp) 	  # Load $ra
addiu $sp, $sp, 32  # pop frame

sll $t4, $t0, 3 ; multiply counter by 8
add $t5, $t4, $a0 ; memory counter
sw $v0, 0($t5) ; store most significant bits first
sw $v1, 4($t5) ; store least significant bits 32 away
addi $t0, $t0, 1
j mult

multiplication:
mult $a0, $a1 ; multiply values
mfhi $v0        ; store them
mflo $v1
jr $ra      ; jump back


