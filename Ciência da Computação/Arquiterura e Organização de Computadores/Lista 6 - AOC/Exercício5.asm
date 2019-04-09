.data


msg1: .asciiz "Digite o primeiro número:\n"
msg2: .asciiz "Digite o segundo número:\n"
msg3: .asciiz "Digite o terceiro número:\n"

.text
        #$s1 Guarda MAIOR
        #$s2 Guarda Inter
        #$s3 Guarda Menor
        
        li $v0,4
        la $a0,msg1
        syscall
        
        li $v0,5
        syscall
        move $t1,$v0
        
        li $v0,4
        la $a0,msg2
        syscall
        
        li $v0,5
        syscall
        move $t2,$v0
        
        li $v0,4
        la $a0,msg2
        syscall
        
        li $v0,5
        syscall
        move $t3,$v0
        
        bgt $t1,$t2 AmaiorqueB
        j fim1
        
        
        AmaiorqueB:
        bgt $t1,$t3 AmaiorqueBeC
        j fim1
        
        
       	AmaiorqueBeC:
  
       	move $s1,$t1
       	
       	bgt $t2,$t3 BmaiorqueC
       	move $s2,$t3
        move $s3,$t2
        j fim1
 
       	BmaiorqueC:
        
        move $s2,$t2
        move $s3,$t3
        j fim1
        
        
        fim1:
        
        bgt $t2,$t1 BmaiorqueA
        j fim2
        
        
        BmaiorqueA:
        bgt $t2,$t3 BmaiorqueAeC
        j fim2
        
        
       	BmaiorqueAeC:
  
       	move $s1,$t2
       	
       	bgt $t1,$t3 AmaiorqueC
       	move $s2,$t3
        move $s3,$t1
        j fim2
 
       	AmaiorqueC:
        
        move $s2,$t1
        move $s3,$t3
        j fim2
        
        fim2:
        
        bgt $t3,$t1 CmaiorqueA
        j fim3
        
        
        CmaiorqueA:
        bgt $t3,$t2 CmaiorqueAeB
        j fim3
        
        
       	CmaiorqueAeB:
  
       	move $s1,$t3
       	
       	bgt $t1,$t2 AmaiorqueB2
       	move $s2,$t2
        move $s3,$t1
        j fim3
 
       	AmaiorqueB2:
        
        move $s2,$t1
        move $s3,$t2
        j fim3
        
        fim3:
      
        li $v0,10
        
        
        
        
        
        
        
         
        
        
       

    
