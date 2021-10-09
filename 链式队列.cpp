#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int Elemtype;

typedef struct QNode{
    Elemtype data;
    struct QNode *next;
}QNode;

typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;

LinkQueue *Init_Queue(LinkQueue *q){
    q->front=(QNode*)malloc(sizeof(QNode));
    q->rear=q->front;
    return q;
}

LinkQueue *EnQueue(LinkQueue *q,Elemtype e){
    QNode *p=(QNode*)malloc(sizeof(QNode));
    if(!p) cout<<"Enqueue failed!"<<endl;
    else{
        p->data=e;
        p->next=NULL;
        q->rear->next=p;
        q->rear=p;
    }
    return q;
}

LinkQueue *DeQueue(LinkQueue *q){
    QNode *p;
    if(q->front==q->rear) cout<<"The queue is empty"<<endl;
    else{
        p=q->front->next;
        Elemtype e=p->data;
        cout<<e<<" is deleted!"<<endl;
        q->front->next=p->next;
        free(p);
    }
    return q;
}

void Get_Head(LinkQueue *q){
    QNode *p;
    if(q->front==q->rear) cout<<"The queue is empty!"<<endl;
    else{
        p=q->front->next;
        cout<<"The Head of queue is "<<p->data<<endl;
    }
}

void Print_Queue(LinkQueue *q){
    QNode *p;
    p=q->front->next;
    cout<<"Now the queue is ";
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    LinkQueue *q=Init_Queue(q);
    int n,e,a;
    cout<<"Please put in the number of queue: ";
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&e);
        EnQueue(q,e);
    }
    Print_Queue(q);
    cout<<"Please add an element to the queue: ";
    cin>>a;
    EnQueue(q,a);
    Print_Queue(q);

    DeQueue(q);
    
    Get_Head(q);

    Print_Queue(q);

    return 0;
}