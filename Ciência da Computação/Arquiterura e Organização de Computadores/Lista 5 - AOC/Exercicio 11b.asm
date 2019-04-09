.data
.text
.main:

      li $s0,2 #g
      li $s1,0 #h
      
      
      
      bge $s0,$s1,if
      sub $s1,$s1,1
      j exit
      if:
      add $s0,$s0,1
      exit:
