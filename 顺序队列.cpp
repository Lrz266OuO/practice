#include<stdio.h>
#include<stdlib.h>

typedef struct Qnode{
    int *data;
    int front,rear;
    int max;
}*Queue;

Queue CreateQueue(int max){
    Queue q=(Queue)malloc(sizeof(struct Qnode));
    q->data=(int*)malloc(sizeof(int));
    q->front=0;
    q->rear=0;
    q->max=max;
    return q;
}

int isFull(Queue q){
    if((q->rear==q->max)){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Queue q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

void AddQueue(Queue q,int x){
    if(isFull(q)){
        printf("Add failed!\n");
    }
    else{
        q->rear=q->rear+1;
        q->data[q->rear]=x;
    }
}

int OutQueue(Queue q){
    if(isEmpty(q)){
        printf("Out failed!\n");
    }
    else{
        q->front=q->front+1;
        return q->data[q->front];
    }
}

int main(){
    int max,n,x,y;
    Queue q;
    printf("Please put in the max number of the queue: ");
    scanf("%d",&max);
    q=CreateQueue(max);
    printf("Create successfully!\n");
    printf("Please put in the number of the queue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        AddQueue(q,x);
    }
    y=OutQueue(q);
    printf("The top of queue is ");
    printf("%d\n",y);
    printf("Now the queue is ");
    while(!isEmpty(q)){
        y=OutQueue(q);
        printf("%d ",y);
    }
    printf("\n");

    return 0;
}
