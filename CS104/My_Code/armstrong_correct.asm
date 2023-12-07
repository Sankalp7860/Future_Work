.data
str1:.asciiz "Enter number"
str2:.asciiz "Armstrong"
str3:.asciiz "Not Armstrong"
.text
.globl main
main:

    li $v0,4
    la $a0,str1
    syscall

    li $v0,5
    syscall
    move $t0,$v0


    jal Armstrong

    beq $t1,$t0,Equal
    li $v0,4
    la $a0,str3
    syscall

Equal:
    li $v0,4
    la $a0,str2
    syscall




    li $v0,10
    syscall



Armstrong:

    move $t2,$t0

    li $t1,0
    li $t3,0

    loop:

        rem $t3,$t2,10
        div $t2,$t2,10

        li $t4,1
        li $t5,1

        Cube:
            mul $t5,$t5,$t3
            add $t4,$t4,1
            ble $t4,3,Cube

        add $t1,$t1,$t5
        bne $t2,0,loop


        li $v0,1
        move $a0,$t1
        syscall
        jr $ra