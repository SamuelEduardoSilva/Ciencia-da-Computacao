.data

msg1: .asciiz "Digite a largura do c�modo:\n"
msg2: .asciiz "Digite o comprimento do c�modos:\n"
msg3: .asciiz "A �rea em metros do c�modo �: "
msg4: .asciiz "A pot�ncia em W que devera ser utilizada ser�: "
barran: .asciiz "\n"

.text

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
         
         mul $s0,$t1,$t0
         
         li $v0,4
         la $a0,msg3
         syscall
         
         li $v0,1
         la $a0,($s0)
         syscall
         
         li $v0,4
         la $a0,barran
         syscall
         
         mul $s0,$s0,18
         
         li $v0,4
         la $a0,msg4
         syscall
         
         li $v0,1
         la $a0,($s0)
         syscall
         
         li $v0,4
         la $a0,barran
         syscall
         
         li,$v0,10
         syscall
         
        
         
         
         
         