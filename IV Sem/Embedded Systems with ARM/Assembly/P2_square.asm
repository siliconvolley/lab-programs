	area SQUARE, code, readonly
		
entry
start

	ldr r0, =table
	mov r1, #6
	mov r1, r1, lsl #0x2
	add r0, r0, r1
	ldr r3, [r0]
	
back b back

table
	dcd 0x00000000 ;0^2 = 0
	dcd 0x00000001 ;1^2 = 1
	dcd 0x00000004 ;2^2 = 4
	dcd 0x00000009 ;3^2 = 9
	dcd 0x00000010 ;4^2 = 16
	dcd 0x00000019 ;5^2 = 25
	dcd 0x00000024 ;6^2 = 36
	dcd 0x00000031 ;7^2 = 49
	dcd 0x00000040 ;8^2 = 64
	dcd 0x00000051 ;9^2 = 81
	dcd 0x00000064 ;10^2 = 100
		
	end