#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

/* 
int main(){
    float x;
    scanf("%f",&x);
    //判断
    if(x<0 || x>100){
        printf("超出范围\n");
        return 0;
    }
    else{
        //一位小数点四舍五入
        float x2;
        x2 = 100 - ((int)(10*x + 0.5))/10.0;
        printf("共找零%.1f元：",x2);
        //计算找零钱，张数最少
        int cnt[8] = {0};
        cnt[0] = int(x2/100);
        cnt[1] = int((x2-cnt[0]*100)/50);
        cnt[2] = int((x2-cnt[0]*100-cnt[1]*50)/20);
        cnt[3] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20)/10);
        cnt[4] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10)/5);
        cnt[5] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5)/1);
        cnt[6] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5-cnt[5])/0.5);
        cnt[7] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5-cnt[5]-cnt[6]*0.5)/0.1);
        printf("100元%d张 50元%d张 20元%d张 10元%d张 5元%d张 1元%d张 5角%d张 1角%d张",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[6],cnt[7]);
        return 1;
    }
}
*/ 

int main(){
    //读取
    freopen("random.txt","r",stdin);
	int r[500];
	for(int i=0;i<500;i++){
		scanf("%d",&r[i]);
	}
	fclose(stdin);
	
	//生成随机数
//	int key[10];
//	srand((unsigned)time(NULL)); 
//	for(int i = 0; i < 10; ++i){
//		key[i] = (int)(round(1.0 * rand() / RAND_MAX * 2000));
//	}
	int key[10] = {35,356,359,351,353,358,352,355,354,357}; 
	
	//1)顺序查找
	int cmp[10]={0};
	float cmp1=0,cmp2=0;
	int cnt=0,j;	 
	for(int i=0; i<10; i++){
		for(j = 0; j<500; j++){
			cmp[i] +=1;
			if(key[i] == r[j]){
				break;
			}
		}
		if(j==500){
			cmp2 = cmp2 + cmp[i];
			cnt += 1;
		}
		else{
			cmp1 = cmp1 + cmp[i];
		}
	}
	cmp2 = cmp2/cnt;
	cmp1 = cmp1/(10-cnt);
	printf("顺序查找当key值存在和不存在时，查找一个key值平均进行了%.2f, %.2f次比较\n\n",cmp1,cmp2); 
    
    //2)冒泡排序 (从小到大)
    int temp;
	for(int i=0;i<500-1;i++){
		for(j=0;j<500-i-1;j++){
			if(r[j]>r[j+1]){
				temp = r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
			}
		}
	}
	
	//3)二分查找
	int cmp0[10]={0};
	cmp1=0;
	cmp2=0;
	cnt=0;
	int low, high, mid;
	for(int i=0; i<10; i++){
		low=0;
		high=500-1;
		mid = (low+high)/2;
		while(high != low){
			cmp0[i] += 1;
			if(key[i] == r[mid]){
				break;
			}
			else if(key[i] < r[mid]){
				high = mid;
			}
			else{
				low = mid+1;
			}
			mid = (low+high)/2;
		}
		if (high == low){	//没找到 
			cmp2 = cmp2 + cmp0[i];
			cnt += 1;
		}
		else{
			cmp1 = cmp1 + cmp0[i];
		} 
	} 
	cmp2 = cmp2/cnt;
	cmp1 = cmp1/(10-cnt);
	printf("折半查找当key值存在和不存在时，查找一个key值平均进行了%.2f, %.2f次比较\n\n",cmp1,cmp2); 
    
    getchar();
	return 1;
}
