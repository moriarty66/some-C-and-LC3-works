#include<stdio.h>
#include <string.h>
#include<stdlib.h>

/*
struct student{
 	int stunum;  		//学号
    char name[20];	//姓名
  	float examscore;	//考试成绩
  	float labscore;	//实验成绩
  	float totalmark;	//总评成绩
};

int main(){
    struct student stutable[10];
    struct student *parrray[10];
    freopen("hw11.1-student.txt","r",stdin);
    for(int i=0;i<10;i++){
        scanf("%d %s %f %f",&stutable[i].stunum,&stutable[i].name,&stutable[i].examscore,&stutable[i].labscore);
        stutable[i].totalmark = 0.6*stutable[i].examscore + 0.4*stutable[i].labscore;
        parrray[i] = &stutable[i];       
    }
    //bubble
    struct student *tmp;
    for(int i=0;i<10-1;i++){
        for(int j=0;j<10-i-1;j++){
            if(parrray[j]->totalmark < parrray[j+1]->totalmark){
                tmp = parrray[j];
                parrray[j] = parrray[j+1];
                parrray[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<10;i++){
        printf("%f\n",parrray[i]->totalmark);
    }
}
*/

/*
typedef struct student{
	int stunum;  		//学号
	char name[20];	//姓名
	float examscore;	//考试成绩
	float labscore;	//实验成绩
	float totalmark;	//总评成绩
	struct student * next;  //下一个结点
}LNode,*Link;

Link create(int n){
	Link p,l,tmp;
    p = (Link)malloc(sizeof(LNode));
    p->next = NULL;
    l = p;
    freopen("hw11.1-student.txt","r",stdin);
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
    fclose(stdin);
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

Link delete1(Link head, int stunum){
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
    printf("建立链表\n删除结点\n插入结点\n");
    Link l;
    Link p;
    int n;
    scanf("%d",&n);
    l = create(n);
    p = l;
    while(p!=NULL){
        printf("%d %s %f %f %f\n",p->stunum,p->name,p->examscore,p->labscore,p->totalmark);
        p = p->next; 
    }
    getchar();
    int s;
    scanf("%d",&s);
    l = delete1(l,s);
    p = l;
    for(int i=0;;i++){
        printf("%d %s %f %f %f\n",p->stunum,p->name,p->examscore,p->labscore,p->totalmark);
        p = p->next;
        if(p == NULL) break;
    }
    l = insert(l);
    p = l;
    for(int i=0;;i++){
        printf("%d %s %f %f %f\n",p->stunum,p->name,p->examscore,p->labscore,p->totalmark);
        p = p->next;
        if(p == NULL) break;
    }
}
*/




