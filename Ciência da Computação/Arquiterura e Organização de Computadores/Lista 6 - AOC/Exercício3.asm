.data

msg1: .asciiz "Digite a largura do cômodo:\n"
msg2: .asciiz "Digite o comprimento do cômodos:\n"
msg3: .asciiz "A área em metros do cômodo é: "
msg4: .asciiz "A potência em W que devera ser utilizada será: "
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
         
        
         
         
         
         