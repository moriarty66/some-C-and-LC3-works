#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

/* 
int main(){
    float x;
    scanf("%f",&x);
    //�ж�
    if(x<0 || x>100){
        printf("������Χ\n");
        return 0;
    }
    else{
        //һλС������������
        float x2;
        x2 = 100 - ((int)(10*x + 0.5))/10.0;
        printf("������%.1fԪ��",x2);
        //��������Ǯ����������
        int cnt[8] = {0};
        cnt[0] = int(x2/100);
        cnt[1] = int((x2-cnt[0]*100)/50);
        cnt[2] = int((x2-cnt[0]*100-cnt[1]*50)/20);
        cnt[3] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20)/10);
        cnt[4] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10)/5);
        cnt[5] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5)/1);
        cnt[6] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5-cnt[5])/0.5);
        cnt[7] = int((x2-cnt[0]*100-cnt[1]*50-cnt[2]*20-cnt[3]*10-cnt[4]*5-cnt[5]-cnt[6]*0.5)/0.1);
        printf("100Ԫ%d�� 50Ԫ%d�� 20Ԫ%d�� 10Ԫ%d�� 5Ԫ%d�� 1Ԫ%d�� 5��%d�� 1��%d��",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[6],cnt[7]);
        return 1;
    }
}
*/ 

int main(){
    //��ȡ
    freopen("random.txt","r",stdin);
	int r[500];
	for(int i=0;i<500;i++){
		scanf("%d",&r[i]);
	}
	fclose(stdin);
	
	//���������
//	int key[10];
//	srand((unsigned)time(NULL)); 
//	for(int i = 0; i < 10; ++i){
//		key[i] = (int)(round(1.0 * rand() / RAND_MAX * 2000));
//	}
	int key[10] = {35,356,359,351,353,358,352,355,354,357}; 
	
	//1)˳�����
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
	printf("˳����ҵ�keyֵ���ںͲ�����ʱ������һ��keyֵƽ��������%.2f, %.2f�αȽ�\n\n",cmp1,cmp2); 
    
    //2)ð������ (��С����)
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
	
	//3)���ֲ���
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
		if (high == low){	//û�ҵ� 
			cmp2 = cmp2 + cmp0[i];
			cnt += 1;
		}
		else{
			cmp1 = cmp1 + cmp0[i];
		} 
	} 
	cmp2 = cmp2/cnt;
	cmp1 = cmp1/(10-cnt);
	printf("�۰���ҵ�keyֵ���ںͲ�����ʱ������һ��keyֵƽ��������%.2f, %.2f�αȽ�\n\n",cmp1,cmp2); 
    
    getchar();
	return 1;
}
