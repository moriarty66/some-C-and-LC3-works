#include <stdio.h>
#include <string.h>
#include <math.h>

int  goodbrackets(char str[]){
    int cnt=0;
    int i=0;
    while(str[i]){
        if(str[i]=='(') cnt += 1;
        else if(str[i]==')'){    
            cnt -= 1;
            if(cnt<0)   break;
        }
        i++;
    }
    if(cnt == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void transpose(int matrix[][5]){ //5*5数组转置 
	int tmp[5][5];
 	for(int i=0; i<5; i++){
 		for(int j=0; j<5; j++){
		 	tmp[i][j] = matrix[j][i];
		 	printf("%d\t",tmp[i][j]);
		}
		printf("\n");
	}
 }
 
int  wordcounter( char str[ ] ){
	int i = 0;
	int cnt=0,word;
	while(str[i]){
		if((str[i]==' ') || !((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))){
			word = 0;	//状态置为0 
		}
		else if(word == 0){
			word = 1;
			cnt += 1;
		} 
		i++;
	}
	return cnt;
}

int main(){
    int num = 0;
	printf("输入几就运行第几题（999退出）\n");   
    while(num != 999){
        scanf("%d",&num);
        switch(num){
            case 1:
                char str[100];
                getchar();
                gets(str);
                int s;
				s = goodbrackets(str);
                if(s == 1){
                	printf("true\n");
				}
				else{
					printf("false\n");
				}
                break;
            case 2:
            	int m[5][5];
            	for(int i=0; i<5; i++){
            		for(int j=0; j<5; j++){
            			scanf("%d",&m[i][j]);
					}
				}
				transpose(m);
				printf("\n");
				break;
            case 3:
            	char st[100];
            	getchar();
            	gets(st);
            	int cnt;
            	cnt = wordcounter(st);
            	printf("有%d个单词\n",cnt);
            	break;
            default: printf("没这功能，重输\n");
        }
    }
    return 1;
}
