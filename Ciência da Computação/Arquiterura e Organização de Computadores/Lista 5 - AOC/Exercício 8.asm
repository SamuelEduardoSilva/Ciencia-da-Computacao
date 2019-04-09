.data
.text
.main:

      li $s0,1 #a
      li $s1,2 #b
      li $s2,3 #c
      
      
      add $s0,$s1,$s0
      add $s2,$s2,$s2
      sub $s0,$s0,$s2