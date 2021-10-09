#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct{
    Elemtype *base;
    int front;
    int rear;
}SqQueue;

void Init_Queue(SqQueue *q){
    q->base=(Elemtype*)malloc(500*sizeof(Elemtype));
    if(!q->base) exit(1);
    q->front=0;
    q->rear=0;
}

int Length_of_Queue(SqQueue *q){
    int e;
    e=(q->rear-q->front+500)%500;
    return e;
}

void EnQueue(SqQueue *q,Elemtype e){
    if((q->rear+1)%500==q->front) exit(1);
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%500;
}

void DeQueue(SqQueue *q){
    if(q->front==q->rear) exit(1);
    q->front=(q->front+1)%500;
}

Elemtype GetHead(SqQueue *q){
    return q->base[q->front];
}

int main(){
    int n,t,x;
    SqQueue f,*q;
    q=&f;
    Init_Queue(q);
    printf("Please put in the row of YangHui_SanJiao: ");
    scanf("%d",&n);
    EnQueue(q,1);
    for(int i=2;i<=n+1;i++){
        EnQueue(q,1);
        for(int j=1;j<=i-2;j++){
            t=GetHead(q);
            DeQueue(q);
            printf("%4d",t);
            x=GetHead(q);
            t+=x;
            EnQueue(q,t);
        }
        EnQueue(q,1);
        printf("%4d",GetHead(q));
        DeQueue(q);
        printf("\n");
    }
    while(q->front==q->rear){
        printf("%4d",GetHead(q));
        DeQueue(q);
    }

    return 0;
}