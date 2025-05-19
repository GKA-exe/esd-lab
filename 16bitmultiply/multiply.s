	area multiply, code, readonly
	export __main
	
num1 dcd 0x55555555
num2 dcd 0x33333333

__main
	ldr r0, num1
	ldr r1, num2
	umull r4, r3, r1, r0
	ldr r7, =lower32
	str r4, [r7]
	ldr r8, =upper32
	str r3, [r8]
	
	area product, data, readwrite
lower32 dcd 0x0
upper32 dcd 0x0
	end