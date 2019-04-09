.data

mgs1: .asciiz "Digite o primeiro número:\n"
msg2: .asciiz "Digite o segundo número:\n"
resposta: .asciiz "Resposta = "

.text

      li,$v0,4
      la,$a0,mgs1
      syscall
      
      li,$v0,5
      syscall
      move $t0,$v0
      
      li,$v0,4
      la,$a0,msg2
      syscall
      
      li,$v0,5
      syscall
      move $t1,$v0
      
      add $s0,$t0,$t1
      
      li,$v0,4
      la,$a0,resposta
      syscall
      
      bgt $s0,20 if
      sub $s0,$s0,5
      
      j fim
      
      if:
      addi,$s0,$s0,8
      
      
      fim:
      li,$v0,1
      la,$a0,($s0)
      syscall
      
      