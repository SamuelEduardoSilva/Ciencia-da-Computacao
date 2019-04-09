.data

  msg1: .asciiz "O novo valor de X é:\n"

.text

main:


    li $a1,2 #X
    li $a2,6 #Y
    
    jal calcula
    
    move $s0,$v0 # $s0 <- X 
    
    li $v0,4
    la $a0,msg1
    syscall
    
    li $v0,1
    la $a0,($s0)
    syscall
    
    j FIM
    
    calcula:
    
    beq $a1,$a2 fim
    addi $a1,$a1,1
    sub $a2,$a2,1
    j calcula
    
    fim:
    
    move $v0,$a1
    
    jr $ra
    
    
    FIM:
    
    li $v0,10
    syscall
    
    
  