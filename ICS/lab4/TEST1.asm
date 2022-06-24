     .ORIG x3000
BaseA    .FILL  x30A8
TopA    .FILL   x30B0
BaseB    .FILL  x30B2
TopB    .FILL   x30BC
BaseC    .FILL  x30BE
TopC    .FILL   x30CB
BaseD    .FILL  x30CD
TopD    .FILL   x30F7
BaseE    .FILL  x30F9
TopE    .FILL   x3123
BaseF    .FILL  x3125
TopF    .FILL   x313C
BaseG    .FILL  x313E
TopG    .FILL   x314B
BaseH    .FILL  x314D
TopH    .FILL   x315A
N          .FILL x000A
SaveR0     .FILL x2000
SaveR00    .FILL x2001
ASCIIA     .FILL   #65
SAVE       .FILL x2002
SHOW LD R5,TopA          
     LD R2,BaseA
     ADD R3,R2,#5
     NOT R3,R3
     ADD R3,R3,#1
     ADD R3,R3,R5
     BRnp keepon1
     ADD R4,R4,#1
       
keepon1 LD R5,TopB
     LD R2,BaseB
     ADD R3,R2,#5
     NOT R3,R3
     ADD R3,R3,#1
     ADD R3,R3,R5
     BRnp keepon2
     ADD R4,R4,#1
     
keepon2 LD R5,TopC
     LD R2,BaseC
     ADD R3,R2,#5
     NOT R3,R3
     ADD R3,R3,#1
     ADD R3,R3,R5    
     BRnp keepon1
     ADD R4,R4,#1
     NOT R3,R4
     ADD R3,R3,#1
     ADD R3,R3,R4
     BRz Judge
     
     LD R0,BaseA
     LD R6,TopA
     JSR Init
     LD R0,BaseB
     LD R6,TopB
     JSR Init
     LD R0,BaseC
     LD R6,TopC
     JSR Init
player LD R0,SaveR00  ;直接赋值
       NOT R0,R0
       ADD R0,R0,#1
       ADD R0,R0,#1
       ST R0,SaveR00
again  LD R0,SaveR00
       ADD R0,R0,#0
       BRp player1
       BRz player2
player1 LD R0,BaseD
        LD R6,TopD
        BRnzp START
player2 LD R0,BaseE
        LD R6,TopE
        BRnzp START
START  AND R4,R4,#0
L      ST R0,SaveR0
       LDR R0,R0,#0
       OUT
       LD R0,SaveR0
       ADD R0,R0,#1
       NOT R1,R6
       ADD R1,R1,#1
       ADD R1,R1,R0
       BRnz L
       GETC
       OUT
       AND R1,R1,#0
       ADD R1,R1,R0
       GETC
       ST R0,SAVE
       OUT
       LD R0,N
       OUT
       LD R0,SAVE
       LD R2,ASCIIA
       NOT R2,R2
       ADD R2,R2,#1
       ADD R2,R2,R1
       BRn fail ;字母不符合要求
       BRz A    ;字母符合要求（下同）
       ADD R3,R2,#-1
       BRz B
       ADD R3,R2,#-2
       BRz C
       BRp fail
A      LD R5,TopA          
       LD R2,BaseA
       ADD R3,R2,#5
       NOT R3,R3
       ADD R3,R3,#1
       ADD R3,R3,R5 ;判断是否为空
       BRz kong
       ADD R1,R0,#-15
       ADD R1,R1,#-15
       BRnz fail
       ADD R3,R1,#0
       ADD R3,R3,#-3
       BRp fail
       NOT R1,R1
       ADD R1,R1,#1
       ADD R5,R5,R1  ;TOP--
       ST R5,TopA
       ST R2,BaseA
       BRnzp Judge
B      LD R5,TopB
       LD R2,BaseB
       ADD R3,R2,#5
       NOT R3,R3
       ADD R3,R3,#1
       ADD R3,R3,R5
       BRz kong
       ADD R1,R0,#-15
       ADD R1,R1,#-15
       BRnz fail
       ADD R3,R1,#0
       ADD R3,R3,#-5
       BRp fail
       NOT R1,R1
       ADD R1,R1,#1
       ADD R5,R5,R1
       ST R5,TopB
       ST R2,BaseB
       BRnzp Judge
C      LD R5,TopC
       LD R2,BaseC
       ADD R3,R2,#5
       NOT R3,R3
       ADD R3,R3,#1
       ADD R3,R3,R5
       BRz kong
       ADD R1,R0,#-15
       ADD R1,R1,#-15
       BRnz fail
       ADD R3,R1,#0
       ADD R3,R3,#-8
       BRp fail
       NOT R1,R1
       ADD R1,R1,#1
       ADD R5,R5,R1
       ST R5,TopC
       ST R2,BaseC
Judge  LD R0,SaveR00
       ADD R0,R0,#0
       BRp  Player_2_Wins
       BRz  Player_1_Wins
Player_2_Wins   ADD R4,R4,#-3;游戏结束,G是1赢，H是2赢
                BRnp SHOW
                LD R5,TopH
                LD R2,BaseH
                JSR Init
                HALT
Player_1_Wins   ADD R4,R4,#-3
                BRnp SHOW
                LD R5,TopG
                LD R2,BaseG
                JSR Init
                HALT    
kong    ADD R4,R4,#1
        BRnzp fail
fail    LD R0,BaseF
        LD R6,TopF
        JSR Init
        LD R0,N
        OUT
        BRnzp again
Init ST R0,SaveR0
     LDR R0,R0,#0
     OUT
     LD R0,SaveR0
     ADD R0,R0,#1
     NOT R1,R6
     ADD R1,R1,#1
     ADD R1,R1,R0
     BRnz Init
     LD R0,N
     OUT
     RET
.STRINGZ "ROW A:ooo"   
.STRINGZ "ROW B:ooooo"  
.STRINGZ "ROW C:oooooooo"  
.STRINGZ "Player 1, choose a row and number of rocks:"  
.STRINGZ "Player 2, choose a row and number of rocks:"  
.STRINGZ "Invalid move. Try again." 
.STRINGZ "Player 1 Wins."  
.STRINGZ "Player 2 Wins."   
    .END