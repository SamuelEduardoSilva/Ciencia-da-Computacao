.data
.text
.main:
    
         
        li $s0,5
        li $s1,1
        li $t1,1
        li $t2,1
        
        ble $s0 1 exit
   	fib:
        beq $s0,2,exit
   	sub $s0,$s0,1
   	add $s1,$t1,$t2
   	move $t1,$t2
   	move $t2,$s1
   	j fib
   	
   	exit:
   
   