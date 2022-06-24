START
        LW x1,0(x10)
        LW x2,0(x11)
FLAG0   BGEz x1,FLAG1
        ADD x1,x1,x1
        ADDI x1,#1
        ADDI x2,#-1
        BEQz x2,END
        J FLAG0
FLAG1   ADD x1,x1,x1
        ADDI x2,x2,#-1
        BEQz END
        J FLAG0
END     SW x1,0(x13)
DONE
