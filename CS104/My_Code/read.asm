.data
str1: .asciiz "Please Enter the Number: "

.text
.globl main
main:
li $t0,1
li $t2,0 
li $t3,0 

li $v0,4
la $a0,str1
syscall

li $v0,5
syscall
move $t0,$v0

li $v0,4



li $v0,10
syscall

