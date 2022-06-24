.equ 	 Newline  0x0000000A
.equ 	 SAVE	  0x0000000B
.equ 	 SaveR0	  0x0000000C
.equ     SaveR00  0x00000000
.equ	 SAVE0    0x00000000
.equ     ASCIIA   0x00000041
.equ     LastA	  0x0000000E
.equ     LastB	  0x0000000F
.equ     LastC    0x00000010

li x8,0
li x4,0
li x5,0
addi x5,x5,3
sw x5,LastA(x8) 
addi x5,x5,2
sw x5,LastB(x8)
addi x5,x5,3
sw x5,LastC(x8)

CHECKA la x2,Prompt1
	   lw x3,6(x2)
       bnez x3,START
       addi x4,x4,1
       addi x3,x4,-3
       beqz x3,JUDGE
  
CHECKB la x2,Prompt2
	   lw x3,6(x2)
       bnez x3,START
       addi x4,x4,1
       addi x3,x4,-3
       beqz x3,JUDGE
 
CHECKC la x2,Prompt3
	   lw x3,6(x2)
       bnez x3,START
       addi x4,x4,1
       addi x3,x4,-3
       beqz x3,JUDGE
 
START la x0,Prompt1
	  call Init
      la x0,Prompt2
      call Init
      la x0,Prompt3
      call Init
      
      la x0,SaveR00
      not x0,x0
      addi x0,x0,1
      addi x0,x0,1
      sw x0,SaveR00(x8)
again la x0,SaveR00
      bgtz x0,player1
      beqz x0,player2
player1 la x0,Prompt4
		j L
Player2 la x0,Prompt5
		j L
L		sw x0,SaveR0
		lw x0,0(x0)
		beqz x0,Loop
        call printf
        la x0,SaveR0
        addi x0,x0,1
        bnez x0,L
Loop	call scanf
		call printf
        li x1,0
        add x1,x1,x0
        call scanf
        sw x0,SAVE
        call printf
        la x0,Newline
        call printf
        la x0,SAVE
        la x2,ASCIIA
        sub x2,x1,x2
        bltz x2,fail
        beqz x2,A
        addi x3,x2,-1
        beqz x3,B
        addi x3,x2,-2
        beqz x3,C
        bgtz x3,fail

A		la x2,Prompt1
		lw x5,6(x2)
        beqz fail
        addi x1,x0,-48
        blez x1,fail
        addi x3,x1,0
        la x5,LastA
        sub x3,x5,x3
        bltz x3,fail
        la x2,Prompt1
        sub x5,x5,x1
        sw x5,LastA(x0)
        addi x5,x5,6
        add x2,x2,x5
        la x0,SAVE
        sw x0,0(x2)
        j CHECKA
B		la x2,Prompt2
		lw x5,6(x2)
        beqz fail
        addi x1,x0,-48
        blez x1,fail
        addi x3,x1,0
        la x5,LastB
        sub x3,x5,x3
        bltz x3,fail
        la x2,Prompt2
        sub x5,x5,x1
        sw x5,LastB(x0)
        addi x5,x5,6
        add x2,x2,x5
        la x0,SAVE
        sw x0,0(x2)
        j CHECKB
C		la x2,Prompt3
		lw x5,6(x2)
        beqz fail
        addi x1,x0,-48
        blez x1,fail
        addi x3,x1,0
        la x5,LastC
        sub x3,x5,x3
        bltz x3,fail
        la x2,Prompt3
        sub x5,x5,x1
        sw x5,LastC(x0)
        addi x5,x5,6
        add x2,x2,x5
        la x0,SAVE
        sw x0,0(x2)
        j CHECKC

JUDGE	la x0,SaveR00
		bgtz x0,Player_2_Wins
        beqz x0,Player_1_Wins
Player_2_Wins	la x0,Prompt8
				call Init
Player_1_Wins	la x0,Prompt7
				call Init
Init	sw x0,SaveR0(x8)
		lw x0,0(x0)
        beqz OK
        auipc ra,0x0
        la x0,SaveR0
        addi x0,x0,1
        bnez x0,Init
OK		la x0,Newline
		auipc ra,0x0
        ret
fail	la x0,Prompt6
		call Init
        j again
Prompt1 .STRINGZ "ROW A:ooo"
Prompt2 .STRINGZ "ROW B:ooooo"  
Prompt3 .STRINGZ "ROW C:oooooooo"  
Prompt4 .STRINGZ "Player1, choose a row and number of rocks:"  
Prompt5 .STRINGZ "Player2, choose a row and number of rocks:"  
Prompt6 .STRINGZ "Invalid move. Try again." 
Prompt7 .STRINGZ "Player1 Wins."  
Prompt8 .STRINGZ "Player2 Wins."