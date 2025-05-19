	area nsum, code, readonly
	export __main
		
__main
	mov r0, #0
	mov r1, #10

summing
	add r0, r1
	sub r1, #1
	cmp r1, #0
	bne summing

	end
