.data

    msg1: .asciiz "O valor de delta é:\n"
    msg2: .asciiz "Erro,delta menor que zero!\n"
.text
   main:
    li $a1,-1 #a
    li $a2,2 #b
    li $a3,3 #c
    
    
    jal delta
    
    move $s4,$v0 # $s4 < - Delta
    
    
    beq $s4,0 erro
    li $v0,4
    la $a0,msg1
    syscall
    
    li $v0,1
    la $a0,($s4)
    syscall
    j FIM
    erro:
    
    li $v0,4
    la $a0,msg2
    syscall
    
    j FIM
    
    delta:
    
    sub $sp,$sp,16
    sw $s0,12($sp)# a x c
    sw $s1,8($sp) # 4 x $s0
    sw $s2,4($sp) # b^2
    sw $s3,0($sp) #r
    
    mul $s0,$a1,$a3
    mul $s1,$s0,4
    mul $s2,$a2,$a2
    sub $s3,$s2,$s1
    
    blt $s3,0 DeltaMenorQueZero
    move $v0,$s3
    j fimfunct
    
    DeltaMenorQueZero:
    move $v0,$zero
    
    fimfunct:
    
    lw $s3,0($sp)
    lw $s2,4($sp)
    lw $s1,8($sp) 
    lw $s0,12($sp)
    
    
    addi $sp,$sp,16
    jr $ra
    
    
    FIM:
    
    li $v0,10
    syscall
    