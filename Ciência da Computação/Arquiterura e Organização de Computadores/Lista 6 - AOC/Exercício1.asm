.data

entrada: .asciiz "Digite o numero:\n"
tabuada: .asciiz "A tabuada desse número eh:\n"
fator:  .asciiz " vezes "
igual: .asciiz " = "
pulalinha: .asciiz "\n"

.text
      
      li $s0,0
      
      li $v0,4
      la $a0,entrada
      syscall
      
      li $v0,5
      syscall
      move $t0,$v0
      
      li $v0,4
      la $a0,tabuada
      syscall
      
     loop:
     beq $s0,11 fim
     
     li,$v0,1
     la,$a0,($t0)
     syscall
     
     li $v0,4
     la $a0,fator
     syscall
     
     li,$v0,1
     la,$a0,($s0)
     syscall
     
     li $v0,4
     la $a0,igual
     syscall
     
     mul $t1,$t0,$s0
     
     li,$v0,1
     la,$a0,($t1)
     syscall
     
     li $v0,4
     la $a0,pulalinha
     syscall
     
     addi $s0,$s0,1
     j loop
     
    
fim:
    li,$v0,10
    syscall     
