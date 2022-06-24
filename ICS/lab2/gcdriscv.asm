	LI a0 0；令a0为0
	MV x3,x1；将x1赋给x3
FLAG1:	BEQ x3,x2,FLAG3；x1号x2值相等跳转FLAG3
	BGT x3,x2,FLAG2;x3比x2大时跳转至FLAG2
	SUB x2,x2,x3；x2=x2-x3
	J FLAG1;无条件跳转到FLAG1
FLAG2:	SUB x3,x3,x2；x3=x3-x2
	J FLAG1；无条件跳转至FLAG1
FLAG3:	ADD x1,x3,a0;x1=x3+0
