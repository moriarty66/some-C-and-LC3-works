#include<stdio.h>
#include<stdlib.h>


int main(){
	freopen("score.txt","r",stdin);
	int ss[30][4];
	for(int i=0;i<30;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&ss[i][j]);
		}
	}
	fclose(stdin);
	float s[30];
	for(int i=0;i<30;i++){
		s[i] = float(ss[i][1]+ss[i][2]+ss[i][3])/3.0;
	}
	//冒泡
	float temp;
	for(int i=0;i<30-1;i++){
		for(int j=0;j<30-i-1;j++){
			if(s[j]<s[j+1]){
				temp = s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	//折半查找
	int low=0,high=29,mid = (low+high)/2;
	int p;
	while(1){
		if(s[mid]==85){
			if(s[mid+1]==85){
				mid = mid+1;
			}
			else{
				p = mid;
				break;
			}
		}
		else if(s[mid]<85){
			if(s[mid-1]>=85){
				p = mid-1;
				break;
			}
			else{
				high = mid;
				mid = (low+mid)/2;	
			}
		}
		else{
			low = mid;
			mid = (mid+high)/2;
		}
	} 
	//输出
	printf("平均分85分及以上共有：%d人\n",p+1); 
	printf("所有人平均成绩从高到低为：\n");
	for(int i=0;i<30;i++){
		printf("%f\n",s[i]);
	}
	return 1;
} 


/* 
int main(){
	int a[20];
	for(int i=0;i<10;i++){
		a[i]=(i+1)*10;
	}
	int b[10]={1,43,72,23,9,87,54,3,55,0};
	for(int i=10;i<20;i++){
		a[i] = b[i-10];
	}
	int temp;
	for(int i=0;i<20-1;i++){
		for(int j=0;j<20-i-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<20;i++){
		printf("%d\n",a[i]);
	}
	return 1;
}
*/

/* 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int soldiers[n];
	for(int j=0;j<n;j++){
		soldiers[j]=1;
	}
	int temp=0;
	int cnt=0;
	int i=0;	//报数 
	printf("死的顺序为：\n");
	while(cnt<n){
		if(i==(n))	i=0;
		if (soldiers[i]==1){
			temp++;
			if(temp==m){
				temp=0;
				soldiers[i]=0;
				cnt++;
				printf("%d ",i+1);
			}
		}
		i++;
	}
	printf("\n");
	printf("活下来的是：%d",i);
}
*/
/*
int main(){
	int A[5][5];
	int B[5][3] = {{3,0,16},{17,-6,9},{0,23,-4},{9,7,0},{4,13,11}};
	int C[5][3];
	int temp=1;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			A[i][j] = temp;
			temp++;
		}
	}
	for(int i =0;i<5;i++){
		for(int j=0;j<3;j++){
			temp = 0;
			for(int k=0;k<5;k++){
				temp = temp+A[i][k]*B[k][j];
			}
			C[i][j]=temp;
			printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
	return 1;
}
*/


