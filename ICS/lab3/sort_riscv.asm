        LI x5 0 //x5赋值为0，之后作为counter
START: 	LI x1 0x00003100        //头指针位置
BEQ 		x1,x0,DONE  //第一个节点为空，结束
ADDI 		x5,x5,1    //开始计数
     	BEQ x8,x5,DONE  //x8为表长
LOOP: 		LW x2,1(x1)     //刷新前的数据
ADDI 		x7,x1,0    //用x7记录刷新前的指针
     	LW x1,0(x1)     //刷新指针，指向下一个节点
     	BEQ x1,x0,DONE  //第二个节点为空，结束
     	LW x3,1(x1)     //刷新后的数据
     	BEQ x1,x0,START //刷新后若为尾指针，开始新一轮
     	BGE x3,x2,LOOP//后一位大于前一位，即按升序排序，则不用交换
    	ADDI x4,x2,0    //将刷新前的数据赋给x4，便于交换位置
     	SW x3,1(x7)     //小的放前面
     	SW x4,1(x1)     //大的放后面
     	J LOOP  //新一轮小循环
DONE: