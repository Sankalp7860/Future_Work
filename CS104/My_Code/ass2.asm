.data
num1: .word 1,2,3,4,5

.text
.globl main
main:
li $t0,1
li $t2,0 
li $t3,0 
la $t1,num1
loop:  lw $t2,0($t1)
       lw $t3,4($t1)
       add $t3,$t2,$t3
       add $t1,4
       add $t0,1
       bne $t0,4,loop

li $v0,1
move $a0,$t3
syscall

li $v0,10
syscall

