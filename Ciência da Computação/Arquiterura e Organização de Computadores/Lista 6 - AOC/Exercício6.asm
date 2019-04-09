.data
msg1: .asciiz "Digite o peso dos peixes:\n"
msg2: .asciiz "Houve excesso,em kgs, de: "
msg3: .asciiz "Houve multa,em R$, de: "
barran: .asciiz "\n"


.text
     
     li,$s0,0 #Excesso
     li,$s1,0 #Multa
     
     li $v0,4
     la $a0,msg1
     syscall
     
     li $v0,5
     syscall
     move $t0,$v0
     
     ble $t0,50,fim
     sub $s0,$t0,50
     mul $s1,$s0,4
     fim:
     
     li $v0,4
     la $a0,msg2
     syscall
     
     li $v0,1
     la $a0,($s0)
     syscall
     
     li $v0,4
     la $a0,barran
     syscall
     
     li $v0,4
     la $a0,msg3
     syscall
     
     li $v0,1
     la $a0,($s1)
     syscall
     
     li $v0,4
     la $a0,barran
     syscall
     
     
     li,$v0,10
     syscall
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    