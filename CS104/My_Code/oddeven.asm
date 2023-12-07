.data 
str1:.asciiz "Please Enter the Number: "
str3: .asciiz "Odd "
str4: .asciiz " Even "

.text
.globl main
main:
li $t0,0
li $t1,0


li $v0,4
la $a0,str1
syscall

li $v0,5
syscall
move $t0,$v0

rem $t1,$t0,2
beq $t1,$zero,even
j odd

even:
    li $v0,4
    la $a0,str4
    syscall
    j exit  

odd:
    li $v0,4
    la $a0,str3
    syscall
    j exit


exit:
     li $v0,10
     syscall