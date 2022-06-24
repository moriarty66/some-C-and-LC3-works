#include <stdio.h>


int main(){
	int a=2,b=3,c=4;
	float x=3.5,y=4.8;
	float temp;
	temp = 3.5+1/2+56%10;
	printf("%f\n",temp);
	temp = a++*1/3;
	printf("%f\n",temp);
	temp = x+a%3*(int)(x+y)%2/4;
	printf("%f\n",temp);
	temp = (float)(a+b)/2+(int)x%(int)y;	//3+3%4
	printf("%f\n",temp);
	
	bool j;
	j = b>c&&b==c;
	printf("%d\n",j);
	j = !(a>b)&&!c||1;
	printf("%d\n",j);
	j = !(x=a)&&(y=b)&&0;
	printf("%d\n",j);
	j = !(a+b)+c-1&&b+c/2;
	printf("%d\n",j);
	j = 1&&30%10>=0&&30%10<=3;
	printf("%d\n",j);
	
	a = 2;
	temp = a+=a+b;
	printf("%f\n",temp);
	a = 2;
	temp = a*=b%c;
	printf("%f\n",temp);
	a = 2;
	temp = a/=c-a;
	printf("%f\n",temp);
	a = 2;
	temp = a+=a-=a*=a;
	printf("%f\n",temp);
	a = 2;
	temp = a=(a=++b,a+5,a/5);	//,表达式丢弃前面的值 
	printf("%f\n",temp);
	a = 2;
	temp = (a>=b>=2)?1:0 ;
	printf("%f\n",temp);
	
	return 0;
} 


/*
int main(){
	int a,b;
	while(1){
    	scanf("%d %d",&a,&b);
	    if(a<=2 && a>=-2){
	        if(b<=2 && b>=-2){
	            printf("yes\n");
	        }
	        else{
	            printf("no\n");
	        }
	    }
	    else{
	        printf("no\n");
	    }
	    if (a == 999){
	    	break;
		}
	}
    return 0;
}
*/
/* 
int main(){
	printf("输入您百分制的成绩：\n");
	int a,temp;
	scanf("%d",&a);
	if(a>100 || a<0){
		printf("超出正常范围。\n");
		return 0;
	}
	else{
		/*
		if(a<=100 && a>=95)	temp = 1;
		else if(a<95 && a>=90)	temp = 2;
		else if(a<90 && a>=85)	temp = 3;
		else if(a<85 && a>=82)	temp = 4;
		else if(a<82 && a>=78)	temp = 5;
		else if(a<78 && a>=75)	temp = 6;
		else if(a<75 && a>=72)	temp = 7;
		else if(a<72 && a>=68)	temp = 8;
		else if(a<68 && a>=65)	temp = 9;
		else if(a==64)	temp = 10;
		else if(a<64 && a>=61)	temp = 11;
		else if(a==60)	temp = 12;
		else	temp = 13;
		
		temp =  a<=100 + a<95 + a<90 + a<85 + a<82 + a<78 + a<75 + a<72 + a<68 + a<65 + a<64 + a<61 + a<60;
		switch(temp){
			case 1:
				printf("百分制=%d，五分制=A+，GPA=4.3",a);break;
			case 2:
				printf("百分制=%d，五分制=A，GPA=4.0",a);break;
			case 3:
				printf("百分制=%d，五分制=A-，GPA=3.7",a);break;
			case 4:
				printf("百分制=%d，五分制=B+，GPA=3.3",a);break;
			case 5:
				printf("百分制=%d，五分制=B，GPA=3.0",a);break;
			case 6:
				printf("百分制=%d，五分制=B-，GPA=2.7",a);break;
			case 7:
				printf("百分制=%d，五分制=C+，GPA=2.3",a);break;
			case 8:
				printf("百分制=%d，五分制=C，GPA=2.0",a);break;
			case 9:
				printf("百分制=%d，五分制=C-，GPA=1.7",a);break;
			case 10:
				printf("百分制=%d，五分制=D+，GPA=1.5",a);break;
			case 11:
				printf("百分制=%d，五分制=D，GPA=1.3",a);break;
			case 12:
				printf("百分制=%d，五分制=D-，GPA=1.0",a);break;
			default:
				printf("百分制=%d，五分制=F，GPA=0",a);break;
		}
	}
	return 1;
}
*/
