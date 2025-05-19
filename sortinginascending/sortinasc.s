	area asc, code, readonly
	export __main

__main
	ldr r0, =0x10000000
	mov r1, #5
	subs r1, r1, #1
	
outloop
	mov r3, r1
	mov r0, #0x10000000
	
inloop
	ldr r2, [r0]
	ldr r4, [r0, #4]
	cmp r4, r2
	bcc skip
	str r4, [r0]
	str r2, [r0, #4]
	
skip
	add r0, #4
	subs r3, r3, #1
	bne inloop
	subs r1, r1, #1
	bne outloop

	end