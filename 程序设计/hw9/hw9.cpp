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
       //ð������ (��С����)
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
	printf("(999�˳�)\n");
    int i=0,j,k,n,m;
    float res;
    float (*fun)(float);//����ָ������ָ�����
    float integral (float a,float b,float (*fun)(float),int n);//nΪ���������䣨b-a)�ֳ�n�ȷ֣���n��ֵԽ���ʱ����Խ��ȷ����ѧ�ϵĶ�����ȡ�����
    float fsin(float);//sin x����������
    float fcos(float);//cos x����������
    float fexp(float);//e^x ����������
    while(i!=999){
	    printf ("��������ֵ�����\n");
	    scanf ("%d",&m);
	    printf ("��������ֵ�����\n");
	    scanf ("%d",&n);
	    printf("��������Ҫ����ĺ����ľ��庯��(999�˳�)\n");
	    printf("1.sin(x) 2.cos(x) 3.e^x\n");
    
	    scanf ("%d",&i);
	    switch(i)
	    {
	    case 1:
	        fun=fsin;//������ַ����ڣ�����ָ������������ǿ
	        break;
	 
	    case 2:
	        fun=fcos;
	        break;
	    case 3:
	        fun=fexp;
	    }
	    printf ("����Ľ��Ϊ\n");
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
    //���η�����,������ת��Ϊ������͵���ʽ
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
 
