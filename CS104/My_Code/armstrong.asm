.data
str1: .asciiz "Please Enter the Number: "
msg1: .asciiz "Armstrong"
msg2: .asciiz "Not Armstrong"
.text
.globl main
main:
li $t0,0
li $t1,0
li $t2,0
li $t3,0
li $t4,0
li $t5,0
li $t6,0
li $t7,0


li $v0,4
la $a0,str1
syscall

li $v0,5
syscall
move $t0,$v0

move $t2,$t0
move $t6,$t0
loop1:
      div $t2,$t2,10
      add $t1,$t1,1
      bne $t2,$zero,loop1
move $t4,$t1
loop2:
      rem $t2,$t6,10
      div $t6,$t6,10
      move $t3,$t2
      sub $t4,$t4,1
      loop3:
            mul $t3,$t3,$t2
            sub $t4,$t4,1
            bne $t4,$zero,loop3
      move $t4,$t1
      add $t5,$t5,$t3
      sub $t7,$t7,1
      bne $t7,$zero,loop2

beq $t0,$t5,loop4
j loop5
 loop4:   
      li $v0,4
      la $a0,msg1
      syscall
      j exit

loop5:
    li $v0,4
    la $a0,msg2
      syscall
      j exit



exit:
     li $v0,10
     syscall