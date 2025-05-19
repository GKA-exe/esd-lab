	area onezero, code, readonly
	export __main

__main
	mov r2, #0
	mov r3, #0
	mov r7, #2
	ldr r6, =value

loop
	mov r1, #32
	ldr r0, [r6], #4

loop0
	lsls r0, #1
	bcs ones

zeroes
	add r3, r3, #1
	b loop1

ones
	add r2, r2, #1
	
loop1
	subs r1, r1, #1
	bne loop0
	subs r7, r7, #1
	cmp r7, #0
	bne loop
	ldr r8, =onescount
	str r2, [r8]
	ldr r4, =zeroescount
	str r3, [r4]

value dcd 0x11111111, 0xaa55aa55
	area result, data, readwrite
onescount dcd 0
zeroescount dcd 0
	end