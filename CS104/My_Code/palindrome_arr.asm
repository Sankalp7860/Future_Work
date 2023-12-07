.data
 number: .word 1, 3, 2, 3, 1, 0
 msg1: .asciiz "Palindrome"
 msg2: .asciiz "Not Palindrome"
.text
.globl main
main:
la $t0, number
li $t1,0
loop1:
    lw $t2, 0($t0)
    beq $t2, $zero, next
    mul $t1, $t1, 10
    add $t1, $t1, $t2
    add $t0, $t0, 4
    j loop1

next:
    move $t3,$t1
    li $t4,0

loop2:
    mul $t4,$t4,10
    rem $t5,$t1,10
    add $t4,$t4,$t5
    div $t1,$t1,10
    bne $t1,$zero,loop2

    bne $t3,$t4,false

li $v0,4
la $a0,msg1
syscall

li $v0,10
syscall

false:
    li $v0,4
    la $a0,msg2
    syscall

li $v0,10
syscall


