.data

 msg1: .asciiz "Preencha aqui com os 6 números:\n"
 msg2: .asciiz "Soma dos números positivos: "
 msg3: .asciiz "Multiplicação dos números negativos: "
 quebralinha: .asciiz "\n"
 
.text 
    
     li $s0,0 #Guarda a soma dos números positivos
     li $s1,1 #Guarda a multiplicação dos números negativos
     li $t0,0 #contador
     
     li $v0,4
     la $a0,msg1
     syscall
     
     preenchimento:
     
     beq $t0,6 fim
     
     addi $t0,$t0,1
     
     li $v0,5
     syscall
     move $t1,$v0
     
     bge $t1,0 positivo
     mul $s1,$s1,$t1
     j preenchimento
  
     positivo:
     add $s0,$s0,$t1
     j preenchimento 
     
     fim:
     li $v0,4
     la $a0,msg2
     syscall
     
     li $v0,1
     la $a0,($s0)
     syscall
     
     li $v0,4
     la $a0,quebralinha
     syscall
     
     li $v0,4
     la $a0,msg3
     syscall
     
     li $v0,1
     la $a0,($s1)
     syscall
     
     li $v0,4
     la $a0,quebralinha
     syscall