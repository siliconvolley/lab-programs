	area FACT, code, readonly
		
entry
start
	mov r0, #7
	mov r1, r0
	
fact
	subs r1, r1, #1
	cmp r1, #1
	beq stop
	mul r3, r0, r1
	mov r0, r3
	bne fact
	
stop
	nop
	nop
	nop
	
	end