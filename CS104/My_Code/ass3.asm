.data 
str1:.asciiz "Please Enter the Number to check prime or not: "
str2: .asciiz "The Number is: "
str3: .asciiz "Prime "
str4: .asciiz " Not Prime "

.text
.globl main
main:
li $t0,0
li $t1,2
li $t2,1
li $t3,1

li $v0,4
la $a0,str1
syscall

li $v0,5
syscall
move $t0,$v0

li $v0,4
la $a0,str2
syscall

sub $t2,$t0,$t2
loop: div $t0,$t1
      mfhi $t3
      beq $t3,0,isprime
      add $t1,1
      bne $t1,$t2,loop

li $v0,4
la $a0,str3
syscall

li $v0,10
syscall

isprime: li $v0,4
           la $a0,str4
           syscall

           li $v0,10
           syscall