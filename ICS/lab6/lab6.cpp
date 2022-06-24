#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

typedef int Status;

typedef struct Node{
    int p;  //ָ���¼�Լ��ڵ�λ��
    int v;  //value
    struct Node *next;
}Node,*Link;

#define B0 {printf(" \n");}
#define B1 {printf("�� \n");}
#define B2 {printf("���� \n");}
#define B3 {printf("������ \n");}
#define B4 {printf("�������� \n");}
#define B5 {printf("���������� \n");}
#define B6 {printf("������������ \n");}
#define B7 {printf("�������������� \n");}
#define B8 {printf("���������������� \n");}
#define P1 printf("Player1, choose a row and number of rocks: ");
#define P2 printf("Player2, choose a row and number of rocks: ");
#define P0 printf("Invalid move. Try again.\n");

Status lab2(int &a, int &b){
    int r,tmp;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
        lab2(a, b);
    }
    else{
        tmp = a/b;
        r = a - b*tmp;
        if(r==0){
        	a = b;
        	printf("x%X \n",a);  //��ʮ���������
            return 1;
		}
        else{
        	a = b;
        	b = r;
        	lab2(a, b);
		}
    }
}

Status lab3(Link &N){   
    Link T;
    int tmp;
    while(N!=NULL){
        T = N->next;
        while(T!=NULL){
            if(N->v>T->v){
                tmp = N->v;
                N->v = T->v;
                T->v = tmp;
                T = T->next;
            }
            else    T = T->next;
        }
        printf("x%X��ֵ��x%X\n",N->p,N->v);
        N = N->next;
    }
}

Status lab4(){
    int a,b,c,r;
    int p1;
    int p=1;    //ÿ����һ��p+1�����ȫ��Ϊ0��ʱ����pΪ�������1ʤ����֮2ʤ
    int counter=0;    //counterΪ3��Ϸ����
    char q,w;
    a=3;
    b=5;
    c=8;
    char line;
    getchar();
    while(1){
        r = p/2;
        if(p == r*2)    P2
        else    P1
        scanf("%c%c%c",&line,&w,&q);
        p1 = w-48;
        if(line<'A' || line>'C')	P0
        else{
            if(line=='A'){
                if(a-p1<0 || p1<=0)  P0
                else{
                    p+=1;
                    a = a-p1;
                    if(a==2){
                        B2
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(a==1){
                        B1
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(a==0){
                        counter+=1;
                        B0
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                } 
            }
            else if(line =='B'){
                if(b-p1<0 || p1<=0)  P0
                else{
                    p+=1;
                    b = b-p1;
                    if(b==4){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        B4
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(b==3){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        B3
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(b==2){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        B2
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(b==1){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        B1
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                    else if(b==0){
                        counter+=1;
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        B0
                        if(c==0)    B0
                        else if(c==1)   B1
                        else if(c==2)   B2
                        else if(c==3)   B3
                        else if(c==4)   B4
                        else if(c==5)   B5
                        else if(c==6)   B6
                        else if(c==7)   B7
                        else if(c==8)   B8
                    }
                }
            }
            else if(line =='C'){
                if(c-p1<0 || p1<=0)  P0
                else{
                    p+=1;
                    c = c-p1;
                    if(c==7){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B7
                    }
                    else if(c==6){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B6
                    }
                    else if(c==5){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B5
                    }
                    else if(c==4){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B4
                    }
                    else if(c==3){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B3
                    }
                    else if(c==2){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B2
                    }
                    else if(c==1){
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B1
                    }
                    else if(c==0){
                        counter+=1;
                        
                        if(a==0)    B0
                        else if(a==1)   B1
                        else if(a==2)   B2
                        else if(a==3)   B3
                        if(b==0)    B0
                        else if(b==1)   B1
                        else if(b==2)   B2
                        else if(b==3)   B3
                        else if(b==4)   B4
                        else if(b==5)   B5
                        B0
                    }
                }
            }
        }
        if(a==0 && b==0 && c==0)    break;
    }
    r = p/2;
    if(p == r*2)    printf("���2ʤ\n");
    else    printf("���1ʤ\n");
    return 1;
}

void delay(){
    int i= 69999999;
    while(i){
        i--;
    }
    return;
}

Status lab5(){
    char p;
    getchar();
    while(1){
        printf("ICS2020 ");
        delay();
        if(kbhit()){
            p = getch();
            if(p == 13)	break;
            else if(p<'0' || p>'9')
                printf("\n%c is not a decimal digit.\n",p);
            else
                printf("\n%c is a decimal digit.\n",p);
        }
    }
    return 1;
}

int main(){
    int lab;
    int a,b;
    Link N,T;
    while(1){
    	system("CLS");
    	printf("����myx����LAB6ȫ������\n");
    	printf("0 ---- ����\n");
    	printf("1 ---- LAB1����д\n");
    	printf("2 ---- LAB2���������\n");
    	printf("3 ---- LAB3����\n");
    	printf("4 ---- LAB4С��Ϸ\n");
    	printf("5 ---- LAB5�ж�\n");
    	scanf("%d", &lab);
    	switch(lab){
        	case 0: return 0;
        	case 1: 
                printf("û��\n");
                break;
            case 2:
                printf("����a��b =\n"); //��ʮ����������
                scanf("%x %x",&a,&b);
                lab2(a, b);
                break;
            case 3:
                printf("��x3000��ʼ��������һ��node��ַ ֵ(��ַ����0�������룩\n");
                N = (Link)malloc(sizeof(Node));
	            if(!N) return -1;
	            N->p = 0x3100;
                N->v = 0;
                T = (Link)malloc(sizeof(Node));
                N->next = T;
                while(1){
                    scanf("%x %x",&a,&b);
                    T->p=a;
                    T->v=b;
                    if(T->p==0) {
                        T->next = NULL;
                        break;
                    }
                    else{
                    	
                        T->next = (Link)malloc(sizeof(Node));
                        T = T->next;
                    }   
                }
                printf("��x%x��ʼ\n",N->p); 
                lab3(N->next);
                break;
            case 4:
                printf("ROW A��");
                B3
                printf("ROW B��");
                B5
                printf("ROW C��");
                B8
                printf("�����1�ȿ�ʼ�����2��ʼ\n");
                lab4();
                break;
            case 5:
                lab5();
                break;
            default:
                printf("û��\n");
                break;
        }
        system("PAUSE");
    }
    return 0;
}
