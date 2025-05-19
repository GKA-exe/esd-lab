	area factorial, code, readonly
	export __main
__main
		mov R0,#5
		mov R1,#1
loop
		mul R1,R0
		subs R0,#1
		bne loop
		ldr R2,=result;
		str R1,[R2];
		
        area res, data, readwrite
result DCD 0X00;
		end
