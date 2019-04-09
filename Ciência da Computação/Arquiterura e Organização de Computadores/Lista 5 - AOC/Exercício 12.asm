.data
.text
.main:

      li $t0,11 
      li $t1,9 
      li $t2,0 
      
      loop:
      beq $t1,0,fim
      add $t2,$t2,$t0
      sub $t1,$t1,1
      j loop
      
      fim:
      
