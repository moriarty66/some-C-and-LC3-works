#include<stdio.h>

int func1(int i){
	int temp = 0;
	for(int j=1;j<=i;j++){
		temp = temp+j;
	}
	temp = temp - i + 1;
	while(i>0){
		printf("%d ",temp);
		temp+=1;
		i-=1; 
	}
	printf("\n");
	return 1;
}
int q1(){
	printf("输入一个数n："); 
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++){
		func1(i);
	}
	return 1;
}

int q2(){
	printf("输入一个数n："); 
	int n;
	scanf("%d",&n);
	for(int i = n; i>=1; i--){
		func1(i);
	}
	return 1;
}

int func2(int i){
	long double temp = i;
	if(temp==1){
		return 1;
	}
	else{
		return temp*func2(temp-1);
	}
}
int q3(){
	unsigned long long temp;
	int s,m;
	unsigned long long sum=0;
	printf("n的大小：");
	scanf("%d",&s);
	for(int n=1;n<=s;n++){ 
		m = n;
		temp = 1;
		while(m>0){
			temp = temp*m;
			m = m-1;
		}
		sum = sum+temp;
	}
	printf("%llu",sum);
	return 1;
}

int q4(){
	int pri[500]={0};
	int c = 1,j=0;
	pri[0]=2;
	for(int i=1; (2*i+1)<=500; i++){
		for(j=0; j<c; j++){
			if((2*i+1)%pri[j]==0){
				break;
			}
		} 
		if(j==c){
			c+=1;
			pri[c-1] = 2*i+1;
		}
	}
	if(c<10){
		printf("没有10个素数");
	}
	else{
		int sum = 0;
		for(int n = c-10; n<c-1; n++){
			printf("%d+",pri[n]);
			sum = sum + pri[n];
		}
		sum = sum + pri[c-1];
		printf("%d = %d",pri[c-1],sum);
	}
	return 1;
}


int main(){
	int i;
	while(1){
		printf("输入几运行第几题，输入999退出:\n");
		scanf("%d",&i);
		if(i==999)	break;
		else{
			switch(i){
				case 1:	q1();break;
				case 2:	q2();break;
				case 3:	q3();break;
				case 4:	q4();break;
				default: printf("没这功能，重输\n");
			}
			printf("\n\n");
		}
	}
	return 1;
}
