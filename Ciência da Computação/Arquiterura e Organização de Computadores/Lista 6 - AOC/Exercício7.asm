.data

msg: .asciiz "Digite os 6 números:\n"
maior:  .asciiz "O maior número é: "
menor: .asciiz "O menor número é: "
barran: .asciiz "\n"
.text
   
    li,$v0,4
    la,$a0,msg
    syscall
    
    # t1 = maior
    # t2 = menor
    
    
    li $v0,5
    syscall
    move $s1,$v0
    
    move $t1,$s1
    move $t2,$s1
   
    
    li $v0,5
    syscall
    move $s2,$v0
    
    blt $s2,$t1 t1
    move $t1,$s2
    j continue1
    t1:
    move $t2,$s2
    
    continue1:
    
    li $v0,5
    syscall
    move $s3,$v0
    
    blt $s3,$t1 t2
    move $t1,$s3
    j continue2
    t2:
    move $t2,$s3
    
    continue2:
    
    li $v0,5
    syscall
    move $s4,$v0
    
    blt $s4,$t1 t3
    move $t1,$s4
    j continue3
    t3:
    move $t2,$s4
    
    continue3:
    
    li $v0,5
    syscall
    move $s5,$v0
    
    blt $s5,$t1 t4
    move $t1,$s5
    j continue4
    t4:
    move $t2,$s2
    
    continue4:
    
    li $v0,5
    syscall
    move $s6,$v0
    
    blt $s6,$t1 t5
    move $t1,$s6
    j continue5
    t5:
    move $t2,$s2
    
    continue5:
    
    
    li,$v0,4
    la,$a0,maior
    syscall
    
    li,$v0,1
    la,$a0,($t1)
    syscall
    
    li,$v0,4
    la,$a0,barran
    syscall
    
    li,$v0,4
    la,$a0,menor
    syscall
    
    li,$v0,1
    la,$a0,($t2)
    syscall
    
    li,$v0,4
    la,$a0,barran
    syscall
    
    li $v0,10
    syscall
    
    
    