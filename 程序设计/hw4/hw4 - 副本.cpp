#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	float f1[n],f2[n],sum=2.0;
	if(n==1){
		printf("2.00");
	}
	else{
		f1[0]=2;
		f1[1]=3;
		f2[0]=1;
		f2[1]=2;
		sum = 2+3/2.0;
		for(int i=2; i<n; i++){
			f1[i]=f1[i-2]+f1[i-1];
			f2[i]=f2[i-2]+f2[i-1];
			sum = sum+ f1[i]/f2[i];
		}
		printf("%.2f",sum);
	}
}