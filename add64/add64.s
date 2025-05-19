	area add64, code, readonly
	export __main
		
__main
	ldr r0, =value1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, =value2
	ldr r3, [r0]
	ldr r4, [r0, #4]
	
	adds r6, r2, r4
	adc r5, r1, r3
	ldr r0, =result
	str r5, [r0]
	str r6, [r0, #4]
	
	mov r0, #0
	
	align
value1 dcd 0x12a2e640, 0xf2100123
value2 dcd 0x001019bf, 0x4002bf51
result dcd 0
	end