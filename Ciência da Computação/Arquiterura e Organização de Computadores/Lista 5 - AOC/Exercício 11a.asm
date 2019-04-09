.data
.text
.main:

      li $s0,2 #g
      li $s1,0 #h
      
      
      
      bgt $s0,$s1,if
      sub $s0,$s0,$s1
      j exit
      if:
      add $s0,$s0,$s1
      exit: