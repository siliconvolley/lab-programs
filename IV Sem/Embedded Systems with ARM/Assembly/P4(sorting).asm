	area sorting, code, readonly
		
entry
start
	mov r3, #4
	
nxtpass
	ldr r0, =table
	mov r4, #4
	
nxtcmp
	ldr r1, [r0]
	add r0, r0, #4
	ldr r2, [r0]
	cmp r1, r2
	bls noexch
	str r1, [r0]
	add r0, r0, #4
	str r2, [r0]
	add r0, r0, #4
	
noexch
	subs r4, #1
	bne nxtcmp
	subs r3, #1
	bne nxtpass
	
back b back

	area sort, data, readwrite
	
table 
	dcd 0x40000000
	dcd 0x22222222
	dcd 0xAAAAAAAA
	dcd 0xCCCCCCCC
	dcd 0x88888888
	
	end