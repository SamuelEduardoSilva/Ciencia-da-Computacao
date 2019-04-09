.data

   msg1: .asciiz "Digite o sexo:\n"
   msg2: .asciiz "Digite a idade:\n"
   msg3: .asciiz "Pessoas de sexo feminino: "
   msg4: .asciiz "Pessoas de sexo masculino com mais de 30 anos: "
   quebralinha: .asciiz "\n"
   
.text
      li $s0,0
      li $s1,0 #conta mulheres
      li $s2,0 #conta homens com mais de 30
      preenchimento:
        beq $s0,7,fim
        addi $s0,$s0,1
        
      	li $v0,4
      	la $a0,msg1
      	syscall
      	
      	li $v0,5
      	syscall
      	move $t0,$v0
      	
      	li $v0,4
      	la $a0,msg2
      	syscall
      	
      	li $v0,5
      	syscall
      	move $t1,$v0
      	
      	li $v0,4
      	la $a0,quebralinha
      	syscall
      	
      	beq $t0,1 ehhomem
      	addi $s1,$s1,1
        j preenchimento
      	ehhomem:
      	bgt $t1,30 temmaisde30
      	j preenchimento
      	temmaisde30:
      	addi $s2,$s2,1
      	j preenchimento
      	
      	fim:
      	
      	li $v0,4
      	la $a0,msg3
      	syscall
      	
      	li $v0,1
      	la $a0,($s1)
      	syscall
      	
      	li $v0,4
      	la $a0,quebralinha
      	syscall
      	
      	li $v0,4
      	la $a0,msg4
      	syscall
      	
      	li $v0,1
      	la $a0,($s2)
      	syscall
      	
      	li $v0,4
      	la $a0,quebralinha
      	syscall
      	
      	li $v0,10
      	syscall
      	
      	
        
      	
      