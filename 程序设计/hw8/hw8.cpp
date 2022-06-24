#include<stdio.h>


float avg1(float x[]){ 
    float sum=0,averg;
    int i = 1;
    while(i<6){
        sum += x[i];
        i++;
    }
    averg = sum/5.0;
    return averg;
}
float *avg2(float x[][6]){ 
    float sum;
    static float averg[5];
    for(int j=1;j<6;j++){
        sum = 0;
        for(int i=0;i<10;i++){
            sum += x[i][j];
        }
        averg[j-1] = sum/10.0;
    }
    return averg;
}
int *max(float x[][6]){
    float m = x[0][1];
    static int pos[2];
    for(int i=0; i<10; i++){
        for (int j=1;j<6;j++){
            if(m<x[i][j]){
                m = x[i][j];
                pos[0] = i+1;
                pos[1] = j;
            }
        }
    }
    return pos;
}
float var(float x[][6]){
    float averg = 0;
    for(int i=0;i<10;i++){
        averg += avg1(x[i])/10;
    }
    float xx;
    for(int i=0;i<10;i++){
    
            xx += avg1(x[i])*avg1(x[i]);
        
    }
    xx = xx/10;
    float seg;
    seg = xx - averg*averg;
    return seg;
}
int main(){
    freopen("data.txt","r",stdin);
	float r[10][6];
	for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            scanf("%f",&r[i][j]);
        }
	}
	fclose(stdin);
    //1)
    float a;
    for(int i=0;i<10;i++){
        a = avg1(r[i]);
        printf("第%d个学生的平均分为：%.2f\n",(i+1),a);
    }
    //2)
    float *p;
    p = avg2(r);
    for(int i=0;i<5;i++){
        printf("科目%d的平均分为：%.2f\n",(i+1),*(p+i));
    }
    //3)
    int *m;
    m = max(r);
    printf("最高分为：学生%d，课程%d\n",*m,*(m+1));
    //4)
    float v;
    v = var(r);
    printf("平均分方差为：%.2f\n",v);
    return 1;
}

/* 
int *selection_sort(int *array, int n){
	int temp = *array;
    int pos;
    if(n==1)    return array;
    for(int i=0;i<n;i++){
        if(temp<array[i]){
            temp = *(array+i);
            pos = i;
        }
    }
    temp = *(array+n-1);
    *(array+n-1)=*(array+pos);
    *(array+pos)= temp;
    selection_sort(array,n-1);
}
int main(){
    int a[12] = {11 ,188, 768,  1377, 12, 228, 902, 740 ,1326 ,1987 ,41, 1478};
    int *p;
    p = selection_sort(a,12);
    for(int i=0;i<12;i++){
        printf("%d ",*(p+i));
    }
    return 1;
}
*/ 
/*
#define swap(a,b) {int t; t=a; a=b; b=t; }


int main(){
    int a = 1, b = 2;
    swap(a,b);
    printf("%d %d\n",a,b);
    printf("当前行号：%d\n文件名:%s\n函数名：%s\n", __LINE__, __FILE__, __func__) ;
    #ifdef _WIN32
    printf(" _WIN32有定义\n");
    #endif
    #ifdef _WIN64
    printf(" _WIN64有定义\n");
    #endif
    #ifdef __CYGWIN__
    printf(" __CYGWIN__有定义\n");
    #endif
    #ifdef __gnu_linux__
    printf(" __gnu_linux__有定义\n");
    #endif
    #ifdef __MINGW32__
    printf(" __MINGW32__有定义\n");
    #endif
    return 1;
}
*/
