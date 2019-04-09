.data

msg1: .asciiz "Digite o valor do salário mínimo:\n"
msg2: .asciiz "Digite o valor do salário do funcionário\n"
msg3: .asciiz "Esse funcionário ganha "
msg4: .asciiz " salários mínimos !\n"

.text


          li $v0,4
          la $a0,msg1
          syscall
          
          li $v0,5
          syscall
          move,$t1,$v0
          
          li $v0,4
          la $a0,msg2
          syscall
          
          li $v0,5
          syscall
          move,$t2,$v0
          
          div $t0,$t2,$t1
          
          li $v0,4
          la $a0,msg3
          syscall
          
          li $v0,1
          la $a0,($t0)
          syscall
          
          li $v0,4
          la $a0,msg4
          syscall
          
          
          li,$v0,10
          syscall
          
          
