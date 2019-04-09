.data

msg1: .asciiz "Preencha aqui o vetor de cinco posições:\n"
msg2: .asciiz "Maior elemento do vetor:\n"
vetor: .space 20

.text

	li $a1,5 #argumento da função
	la $t0,0 #guarda índice do vetor
	li $s0,0, #contador
	
	
	li,$v0,4
	la,$a0,msg1
	syscall
	
	preenche:
	
	beq $s0,5 fim
	addi $s0,$s0,1
	
	li,$v0,5
	syscall
	sw $v0,vetor($t0)
	addi $t0,$t0,4
        j preenche
        
        fim:
        
        li,$v0,4
	la,$a0,msg2
	syscall
        jal EncontraMaior
        
        
        
        move $t5,$v0
        li $v0, 1
	la $a0,($t5)
	syscall 
	j Exit
        
        
        EncontraMaior:
        la $t0,-4
        addi $sp, $sp, -8
        sw $t1,4($sp) #guarda o maior elemento
        sw $t2,0($sp) #contador
        
        li $t2,0
        rodavetor:
        addi $t2,$t2,1
        addi $t0,$t0,4
        beq $t2,1 Iigual1
        bgt $t2,$a1 fimVetor
        lw $t3,vetor($t0)
        blt $t3,$t1 rodavetor
        move $t1,$t3
        j rodavetor
        Iigual1:
        lw $t3,vetor($t0)
        move $t1,$t3
        j rodavetor
        
        fimVetor:
        
        move $v0,$t1
        
        sw $t2,0($sp) 
        sw $t1,4($sp)
        addi $sp, $sp, 8
        
        jr $ra
        
     
        
        
         
        Exit:
li $v0, 10
syscall         
        
        
        
	
	
