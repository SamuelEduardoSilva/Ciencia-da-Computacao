.data
.text

     li $s0,2 #a
     li $s1,2 #b
     li $s2,0
     move $t1,$s0 #a temporario
     move $t2,$s1 #b temporario
     
     mul $s2,$t1,$t1
     mul $s2,$s2,$t1
     
     move $t1,$s0 
     
     mul $t1,$t1,$t1
     mul $t1,$t1,6
     mul $t1,$t1,$s1
     
     add $s2,$s2,$t1
     
     move $t2,$s1
     
     mul $t2,$t2,$t2
     mul $t2,$t2,$s1
     mul $t2,$t2,12
     
     add $s2,$s2,$t2
     
     move $t2,$s1
     
     mul $t2,$t2,$t2
     mul $t2,$t2,$s1
     mul $t2,$t2,8
     
     add $s2,$s2,$t2
    
     