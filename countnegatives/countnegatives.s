	area negative, code, readonly
	export __main
		
__main
	mov r5, #7
	mov r2, #0
	ldr r4, =array
	
loop
	ldr r1, [r4], #4
	lsls r1, #1
	bcs found
	b loop1

found
	add r2, r2, #1

loop1
	subs r5, r5, #1
	cmp r5, #0
	bne loop
	ldr r6, =negcount
	str r2, [r6]
	
	align
array dcd 0x12345678, 0x87654321, 0x11111111, 0x33333333, 0x86543218, 0x24234134
	
	area result, data, readwrite
negcount dcd 0
	end