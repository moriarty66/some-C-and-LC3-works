 ; R0是当前循环开始地址，R1是当前地址对应节点的值
 ; R2是下一个地址，R3是下一个地址对应节点的值
        .ORIG x3000
        LD    R0,BEGIN         ; 第一个点为空，结束
        BRz   END
        LDR   R5,R0,#0         ; 第二个节点为空，结束
        BRz   END
    
FLAG2   LDR   R2,R0,#0         ; R2为下一个地址

FLAG1   LDR   R1,R0,#1         ; R1是当前节点的值
        LDR   R3,R2,#1         ; R3是下一个节点的值
        
COMPARE NOT   R4,R1            ; 比较R1和R3
        ADD   R4,R4,#1
        ADD   R4,R4,R3
        BRzp  JUMP           
        
        STR   R3,R0,#1         ; R3<R1,则交换两个节点的值(地址不变)
        STR   R1,R2,#1
        
JUMP    LDR   R2,R2,#0         ; R2(下一个地址)为空
        LDR   R5,R2,#0
        BRz   JUDGE
        BRnzp FLAG1
        
JUDGE   LDR   R0,R0,#0         ; R0后移，R0移动到尾时，结束
        LDR   R5,R0,#0
        LDR   R5,R5,#0
        BRz   END
        BRnzp FLAG2            ; R0没到尾，则继续大循环
        
END     HALT
BEGIN   .FILL X3100
        .END