#include<stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct LNode{
	int stunum;  		//学号
	char name[20];	//姓名
	float examscore;	//考试成绩
	float labscore;	//实验成绩
	float totalmark;	//总评成绩
	struct LNode * next;  //下一个结点
}LNode,*Link;

void print(Link head){
	Link p;
	p = head;
	while(p != NULL){
        printf("%d %s %f %f %f\n",p->stunum,p->name,p->examscore,p->labscore,p->totalmark);
        p = p->next;  
    }
}

Link create(int n){
	Link p,l,tmp;
    p = (Link)malloc(sizeof(LNode));
    p->next = NULL;
    l = p;
    //freopen("hw11.1-student.txt","r",stdin);
    for(int i=0;i<n-1;i++){
        scanf("%d %s %f %f",&p->stunum,&p->name,&p->examscore,&p->labscore);
        p->totalmark = 0.6* (p->examscore) + 0.4* (p->labscore);
        tmp = (Link)malloc(sizeof(LNode));
        p->next = tmp;
        p = p->next;
    	p->next = NULL;
    }
    scanf("%d %s %f %f",&p->stunum,&p->name,&p->examscore,&p->labscore);
    p->totalmark = 0.6* (p->examscore) + 0.4* (p->labscore);
    //fclose(stdin);
    //bubble
    Link head;
    head = (Link)malloc(sizeof(LNode));
    head->next = l;
    Link tail,q1,q2;
    tail = NULL;
    while((head->next->next) != tail){
        q1 = head;
        q2 = head->next;
        while(q2->next != tail){
            if((q2->totalmark) < (q2->next->totalmark)){
                q1->next = q2->next;
                q2->next = q2->next->next;
                q1->next->next = q2;
                q2 = q1->next;
            }
            q2 = q2->next;
            q1 = q1->next;
        }
        tail = q2;
    }
    tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

Link delete1(Link head,int stunum){
    Link h,tmp,l;
    h = (Link)malloc(sizeof(LNode));
    h->next = head;
    l = h;
    while(h->next->next != NULL){
        if(h->next->stunum == stunum){
            tmp = h->next;
            h->next = h->next->next;
            free(tmp);
            return l->next;
        }
        h = h->next;
    }
    if(h->next->next == NULL){
        if(h->next->stunum == stunum){
            tmp = h->next;
            h->next = NULL;
            free(tmp);
            return l->next;
        }
    }
    else{
    	printf("没找到\n");
        return l->next;
    }
}

Link  insert(Link head){
    Link p,l;
    l = head;
    p = (Link)malloc(sizeof(LNode));
    scanf("%d %s %f %f",&p->stunum,&p->name,&p->examscore,&p->labscore);
    p->totalmark = 0.6* (p->examscore) + 0.4* (p->labscore);
    if(p->totalmark > head->totalmark){
        p->next = head;
        return p;
    }
    while(l->next != NULL){
        if((p->totalmark <= l->totalmark) && (p->totalmark >= l->next->totalmark)){
            p->next = l->next;
            l->next = p;
            return head;
        }
        l = l->next;
    }
    if((p->totalmark <= l->totalmark)){
        l->next = p;
        return head;
    }
}

int main(){
    int m,n=3,s;
    Link l = (Link)malloc(10*sizeof(LNode));
    Link p;
    while(1){
    	system("CLS");
    	printf("请输入功能：\n1.建立链表\n2.删除结点\n3.插入结点\n0.退出\n");
		scanf("%d",&m);
        switch(m){
        	case 0: free(l);return 0;
            case 1:
                getchar();
                l = create(n);
                p = l;
                print(p);
                break;
                
            case 2:
                scanf("%d",&s);
                l = delete1(l,s);
                p = l;
                print(p);
                break;
            case 3:
                l = insert(l);
                p = l;
                print(p);
                break;
            default:
            	printf("没这个功能\n");
                break;
        }
        
        system("PAUSE");
        
    }
}
