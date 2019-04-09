.data
.text
.main:

      li $s0,0 #a
      li $s1,2 #b
      li $s2,3 #c
      
      
      beq $s0,0,if
      add $s0,$s0,$s1
      j exit
      if:
      add $s0,$s0,$s2
      exit: