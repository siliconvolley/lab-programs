	area largest, code, readonly

entry
start

	ldr r0, =array
	mov r3,#4
	ldr r1, [r0]
	
loop	
	add r0, r0, #4
	ldr r2, [r0]
	cmp r1, r2
	bhs next
	mov r1, r2
	
next
	subs r3, r3, #1
	cmp r3, #0
	bne loop
	
back b back
	
array
	dcd 0x11111111
	dcd 0x22222222
	dcd 0xAAAAAAAA
	dcd 0x99999999
	dcd 0x33333333
		
	end