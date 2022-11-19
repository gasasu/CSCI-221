

; assume double floating point number is stored in $f0
; assume length of the list is stored in $a0
; assume pointer to double floating points is stored in $f2

main:
li $t0, 0 ; counter = 0
Loop:
slt $t1, $t0, $a0 ; counter < length
bne $t1, $zero, Add ; if True go to Add
mfc1 $a0, $f0 ; moving MSB of result
mfc1 $a1, $f1 ; moving LSB of result
li $t0, 0x7ff00000 ; load mask
and $t1, $a0, $t0 ; extract esponent
srl $t1, $t1, 20 ; right shift it
move $v0, $t1 ; store exponent in $v0
jr $ra

Add:
sll $t2, $t0, 3 ; multiply counter by 8
add $t2, $t2, $f2 ; find the right address
l.d $f4, 0($t2)  ; load the double
add.d $f2, $f2, $f4 ; perform the arithmetic
addi $t0, $t0, 1 ; increment counter
j Loop ; go back to loop
