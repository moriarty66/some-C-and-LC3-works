#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* 
int main(){
    char c[200];
    gets(c);
    int end[200];
    int len[200]={0},maxlen=0;
    int i=0,j=0;
    int cnt;
    while(c[i]){
        if(!(c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')){
            if(len[j]>maxlen){
                maxlen = len[j];
            }
            end[j] = i-1;
            j++;
        }
        else{
            len[j] += 1;
        }
        i++;
    }
    cnt = j;
    i = 0;
    for(i=0;i<cnt;i++){
        if(len[i]==maxlen){
            for(j=end[i]-maxlen;j<=end[i];j++){
                printf("%c",c[j]);
            }
            printf("\n");
        }
    }
    return 1;
}


int main(){
    char countries[10][40];
    int num[10],i,j;
    for (i=0;i<10;i++){
        gets(countries[i]);
    }
    int len[10];
	char *lensort[10],*inisort[10];
    for(i=0;i<10;i++){
        for(j=0;countries[i][j];j++);
        len[i] = j;
    }
    for (i=0;i<10;i++){
        num[i] = len[i];
        inisort[i] = countries[i];
    }
       //冒泡排序 (从小到大)
    int temp;
	for(i=0;i<9;i++){
		for(j=0;j<10-i-1;j++){
			if(num[j]>num[j+1]){
				temp = num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	printf("\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(num[i]==len[j]){
                lensort[i] = countries[j];
                len[j]=999;
                break;
            }
        }
        printf("%s\n",lensort[i]);
    }
    printf("\n");
    char *tmp;
	for(i=0;i<9;i++){
		for(j=0;j<10-i-1;j++){
			for(int k=0;;k++){
				if(inisort[j][k]>inisort[j+1][k]){
					tmp = inisort[j];
					inisort[j]=inisort[j+1];
					inisort[j+1]=tmp;
					break;
				}
				else if(inisort[j][k]<inisort[j+1][k]){
					break;
				}
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%s\n",inisort[i]);
	}
    
}

*/
int main()
{
	printf("(999退出)\n");
    int i=0,j,k,n,m;
    float res;
    float (*fun)(float);//定义指向函数的指针变量
    float integral (float a,float b,float (*fun)(float),int n);//n为将积分区间（b-a)分成n等分，当n的值越大的时候结果越精确，数学上的定义是取无穷大
    float fsin(float);//sin x函数的声明
    float fcos(float);//cos x函数的声明
    float fexp(float);//e^x 函数的声明
    while(i!=999){
	    printf ("请输入积分的下限\n");
	    scanf ("%d",&m);
	    printf ("请输入积分的上限\n");
	    scanf ("%d",&n);
	    printf("请输入你要计算的函数的具体函数(999退出)\n");
	    printf("1.sin(x) 2.cos(x) 3.e^x\n");
    
	    scanf ("%d",&i);
	    switch(i)
	    {
	    case 1:
	        fun=fsin;//函数地址（入口）交给指针变量，灵活性强
	        break;
	 
	    case 2:
	        fun=fcos;
	        break;
	    case 3:
	        fun=fexp;
	    }
	    printf ("计算的结果为\n");
	    res=integral(m,n,fun,200000);
	    printf("res=%f\n",res);
	}
    return 0;
}
float fsin(float x)
{
   // printf("fsinx=%f\n",x);
    return  sin(x);
}
float fcos(float x)
{
    //printf("fcosx=%f\n",x);
    return cos(x);
}
float fexp(float x)
{
    //getchar();
    //printf("fexp=%f\n",x);
    return exp(x);
}
float integral(float a,float b,float (*fun)(float),int n)
{
    //矩形法计算,定积分转换为连续求和的形式
    int i=0;
    float  x=a,s=0;
    float  h=(b-a)/n;
 
    for (i=1;i<=n;i++)
    {
        x=x+h;
        s=s+((*fun)(x)*h);
 
    }
    return s;
}
 
