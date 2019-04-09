.data
	vetor: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
	
	
	.text
	
	    	li $t2,0
		la $t0,0		
	loop:
	       
		lw $t1, vetor($t0)
		beqz $t1, fim
		add $t2,$t1,$t2
		addi $t0,$t0,4
	    j loop
	fim:
