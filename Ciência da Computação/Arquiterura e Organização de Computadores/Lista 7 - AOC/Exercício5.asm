.data


msg1: .asciiz "Resultado:\n"


.text
    main:
     li $a1,5 # n
     
     
     jal soma
     
     move $s0,$v0
     
     li $v0,4
     la $a0,msg1
     syscall
     
     
     li $v0,1
     la $a0,($s0)
     syscall
     
     j FIM
     
     
     soma:
     addi $sp,$sp,-8
     sw $ra,4($sp)
     sw $a1,0($sp)
     
     slti $t0,$a1,1
     beq $t0,$zero,P
     addi $v0,$zero,0
     addi $sp,$sp,8
     jr $ra
     
     P:
     addi $a1,$a1,-1
     jal soma
     
     lw $a1,0($sp)
     lw $ra,4($sp)
     addi $sp,$sp,8
     
     add $v0,$a1,$v0
     
     jr $ra


    FIM:
    
    li $v0,10
    syscall
   