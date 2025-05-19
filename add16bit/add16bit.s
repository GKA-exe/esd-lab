	AREA arr16, CODE, READONLY
	ENTRY
	EXPORT __main
	
__main
	LDR R0, = Count;
	LDR R1, = Array;
	MOV R2,#0
	LDR R4,[R0]

loop
	LDRH R3,[R1],#4
	ADD R2,R3
	SUBS R4,#1
	CMP R4,#0
	BNE loop
	LDR R5,=Result;
	STR R2,[R5]
	
	AREA MulRes, DATA ,READWRITE
Array  DCD 0x00;
Count DCD 0x00;
Result DCD 0X00;
	END
