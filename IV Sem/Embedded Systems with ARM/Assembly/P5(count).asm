	area count, code, readonly
		
entry
start

	mov r0, #32
	ldr r1, =table
	add r2, r1, #4
	ldr r1, [r1]
	ldr r2, [r2]
	mov r3, #0
	mov r4, #0
	mov r5, #2
	
loop1
	movs r1, r1, ror #1
	bhi higher
	add r4, r4, #1
	subs r0, r0, #1
	bne loop1
	beq finish
	
higher
	add r3, r3, #1
	subs r0, r0, #1
	cmp r0, #0
	bne loop1
	beq finish
	
finish
	mov r0, #32
	mov r1, r2
	subs r5, r5, #1
	cmp r5, #0
	bne loop1
	
	nop
	nop
	
back b back

table
	dcd 0x00000000
	dcd 0xFFFFFFFF
			
	end