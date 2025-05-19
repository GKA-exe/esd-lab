    AREA asc, CODE, READONLY
    EXPORT __main

__main
    LDR r0, =0x10000000
    MOV r5, #5
    SUB r1, r5, #1

outloop
    MOV r3, r1
    LDR r0, =0x10000000

inloop
    LDR r2, [r0]
    LDR r4, [r0, #4]
    CMP r2, r4
    BCC skip
    STR r4, [r0]
    STR r2, [r0, #4]

skip
    ADD r0, r0, #4
    SUBS r3, r3, #1
    BNE inloop

    SUBS r1, r1, #1
    BNE outloop

    END
