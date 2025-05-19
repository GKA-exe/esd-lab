	AREA maxofarr, CODE, READONLY
	EXPORT __main
		
__main
	LDR R0,=array
	MOV R1,#4
	LDR R2,[R0],#4
		
loop
	LDR R3,[R0],#4
	CMP R2,R3
	BHI large
	MOV R2,R3
		
large
	SUBS R1,#1
	CMP R1,#1
	BNE loop
	LDR R4,=result	;r2 has result
	STR R2, [R4]
		

array DCD 0x03;
	  DCD 0x041;
	  DCD 0x05;
	  DCD 0x09;

	area res, data, readwrite
result DCD 0x00;
		END
