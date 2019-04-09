.data

array: .word
msg1: .asciiz "Digite o tamanho do vetor:\n"
msg2: .asciiz "Preencha aqui seu vetor:\n"
msg3: .asciiz "A soma de todos os elementos é:"
msg4: .asciiz "\n"

.text

main:
    
    #$s0 -> tamanho do vetor
    la $t0,0 #índice do vetor
    li $t1,0 #contador
    
    li $v0,4
    la $a0,msg1
    syscall
    
    li $v0,5
    syscall
    move $s0,$v0
    
    li $v0,4
    la $a0,msg2
    syscall
    
    preenche:
    beq $t1,$s0 fim
    
    li $v0,5
    syscall
    sw $v0,array($t0)
    addi $t0,$t0,4
    addi $t1,$t1,1
    j preenche
  
    fim:
    
    move $a0,$s0
    
    jal SomaVetor
    
    move $s5,$v0
    
    li,$v0,4
    la,$a0,msg3
    syscall
    
    li,$v0,1
    la,$a0,($s5)
    syscall
    
    li,$v0,4
    la,$a0,msg4
    syscall
    
    j EXIT
    
    
    
    
    
    SomaVetor:
    la $t0,0
    addi $sp, $sp, -8
    sw $s1,4($sp) #guarda a soma dos elementos
    sw $s2,0($sp) #contador
    
    rodavetor:
    
    beq $s2,$a0 fimvetor
    lw $s3,array($t0)
    add $s1,$s1,$s3
    addi $s2,$s2,1
    addi $t0,$t0,4
    j rodavetor
    fimvetor:
    move $v0,$s1
    lw $s1,0($sp)
    lw $s2,4($sp)
    addi $sp,$sp,8
    
    jr $ra
    
    
    EXIT:
    
    li $v0,10
    syscall
       
    
    
