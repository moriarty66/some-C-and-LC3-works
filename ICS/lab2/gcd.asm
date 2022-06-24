        .ORIG x3000
FLAG1   NOT R2,R1
        ADD R2,R2,#1
        ADD R3,R0,R2
        BRzp FLAG2
        ADD R0,R1,#0
        ADD R1,R3,R1
FLAG2   ADD R0,R0,R2
        BRz FLAG3
        BRp FLAG2
        ADD R0,R1,#0
        ADD R1,R0,R1
        BRnzp FLAG1
FLAG3   ADD R0,R1,#0
        HALT
        .END