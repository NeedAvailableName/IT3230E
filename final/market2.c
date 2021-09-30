#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int id;
    struct Node*next;
}Node;
typedef struct Queue{
    Node*head;
    Node*tail;
}Queue;
typedef struct Link{
    int CashierID;
    int NumberOfCustomer;
    Queue* CustomerID;
    struct Link*next;
    struct Link*prev;
}Link;
Node*makenode(int v)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->id=v;
    p->next=NULL;
    return p;
}
Queue*initQueue(){
    Queue*p=(Queue*)malloc(sizeof(Queue));
    p->head=NULL;
    p->tail=NULL;
    return p;
}
int isempty(Queue*q){
    return  q->head==NULL&&q->tail==NULL;
}
void Push(int v,Queue*q){
    Node*p=makenode(v);
    if(isempty(q)) {
        q->head=p;
        q->tail=p;
        return;
    }
    q->tail->next=p;q->tail=p;
}
Node*Pop(Queue*q){
    if(isempty(q)) return NULL;
    Node*p=q->head;
    q->head=q->head->next;
    if(q->head==NULL)q->tail=NULL;
    return p;
}
Link*makelink(int v){
    Link*p=(Link*)malloc(sizeof(Link));
    p->CashierID=v;
    p->NumberOfCustomer=0;
    p->CustomerID=initQueue();
    p->next=NULL;
    p->prev=NULL;
    return p;
}
Link*CurrentLink;
Link*LastLink;
Link*FirstLink;
void initlink(){
    Link*p=makelink(1);
    Link*q=makelink(2);
    Link*r=makelink(3);
    Link*s=makelink(4);
    p->next=q;q->prev=p;
    q->next=r;r->prev=q;
    r->next=s;s->prev=r;
    s->next=p;p->prev=s;
    LastLink=s;
    CurrentLink=p;
    FirstLink=p;
}
int cnt=4;
int n=4;
Link*addLink(){
    cnt++;
    n++;
    int i=cnt;
    Link*l=makelink(n);
    LastLink->next=l;
    LastLink=l;
    l->next=FirstLink;
    FirstLink->prev=l;
    return l;
}
Link*findLink(int CashierID){
    if(LastLink->CashierID==CashierID) return LastLink;
    Link*p=FirstLink;
    while(p!=LastLink){
        if(p->CashierID==CashierID) return p;
        p=p->next;
    }
    return NULL;
}
Link*findmin(){
    int min=9999;
    Link*Linkmin;
    Link*p=FirstLink;
    while(p!=LastLink)
    {
        if(p->NumberOfCustomer<min)
        {
            min=p->NumberOfCustomer;
            Linkmin=p;
        }
        p=p->next;
    }
    if(LastLink->NumberOfCustomer<min) return LastLink;
    else return Linkmin;
}
void freeall(){
    Link*tmp;
    Link*p=FirstLink->next;
    while(p!=LastLink){
        tmp=p->prev;
        p=p->next;
        free(tmp);
        free(tmp->CustomerID);
    }
    free(LastLink);
}
Link*removeLink(int CashierID){
    if(cnt<=1) {
         return NULL;
    }
    Link*l=findLink(CashierID);
    if(l==NULL) return NULL;
    if(CashierID==CurrentLink->CashierID) CurrentLink=CurrentLink->next;
    if(CashierID==FirstLink->CashierID)FirstLink=FirstLink->next;
    if(CashierID==LastLink->CashierID)LastLink=LastLink->prev;
    l->next->prev=l->prev;
    l->prev->next=l->next;
    cnt--;
    return l;
}
int main(){
    char cmd[50];
    int line;
    int ipt;
    int ID=1;
    int checkid;
    initlink();
    while(1){
     scanf("%s",cmd);
        if(strcmp(cmd,"***")==0) {freeall();break;}
        if(strcmp(cmd,"$Enter")==0){
            printf("%d %d\n",ID,CurrentLink->CashierID);
            Push(ID,CurrentLink->CustomerID);
            ID++;
            CurrentLink->NumberOfCustomer+=1;
            //printf("%d",CurrentLink->NumberOfCustomer);
            CurrentLink=CurrentLink->next;

        }
        if(strcmp(cmd,"$Checkout")==0){
            scanf("%d",&checkid);
            Link*l=findLink(checkid);
            if(l==NULL)printf("Error\n");
            else if(l!=NULL){
            Node*q=Pop(l->CustomerID);
            if(q==NULL) printf("Empty\n");
            else{
            printf("%d\n",q->id);
            l->NumberOfCustomer--;
            free(q);
            }
        }
        }
        if(strcmp(cmd,"$CountNumberCustomerInAllLines")==0){
            int sum=0;
            Link*p=FirstLink;
            while(p!=LastLink){
                sum+=p->NumberOfCustomer;
                p=p->next;
            }
            sum+=LastLink->NumberOfCustomer;
            printf("%d\n",sum);
        }
        if(strcmp(cmd,"$CountNumberCustomerInLine")==0){
            scanf("%d",&line);
            Link*p=findLink(line);
            if(p==NULL) printf("Error\n");
            else printf("%d\n",p->NumberOfCustomer);
        }
        if(strcmp(cmd,"$ListCustomerInLine")==0){
            scanf("%d",&line);
            Link*p=findLink(line);
            if(p==NULL) printf("Error\n");
            else{
                Node*q=p->CustomerID->head;
                while(q!=NULL){
                    printf("%d ",q->id);
                    q=q->next;
                }
                printf("\n");
            }
        }
        if(strcmp(cmd,"$AdvancedEnter")==0){
            Link*p=findmin();
            Push(ID,p->CustomerID);
            printf("%d %d\n",ID,p->CashierID);
            ID++;
            p->NumberOfCustomer++;
        }
        if(strcmp(cmd,"$OpenCashier")==0){
            Link*l=addLink();
            printf("%d\n",l->CashierID);
        }
        if(strcmp(cmd,"$CloseCashier")==0){
            scanf("%d",&line);
            Link*l=removeLink(line);
            if(l==NULL) printf("Error\n");
            else{
                printf("Closed\n");
                while(!isempty(l->CustomerID)){
                Node*n=Pop(l->CustomerID);
                if(n!=NULL){
                Push(n->id,CurrentLink->CustomerID);
                CurrentLink->NumberOfCustomer++;
                CurrentLink=CurrentLink->next;
                }
            }
            }
            free(l);
        }
    }

    return 0;
}
