#include<stdio.h>
#include<stdlib.h>
struct path{
	int x;
	int y;
	struct path *next;
};

typedef struct Link{
	struct path *head;
}link;

void push(link *q,int x,int y){
	struct path *p;
	p=(struct path*)malloc(sizeof(struct path));
	p->x=x;
	p->y=y;
	p->next=q->head;
	q->head=p;
}

void pop(link *q){
	q->head=q->head->next;
}

void r(int a[5][5],int x,int y,link *q){
	if(x<5&&x>=0&&y<5&&y>=0){
		if(x==4&&y==4) return;
		if(a[x][y+1]==0&&(y+1)<5){
			y++;
			push(q,x,y);
			r(a,x,y,q);
			return;
		}
		if(a[x+1][y]==0&&(x+1)<5){
			x++;
			push(q,x,y);
			r(a,x,y,q);
			return;
		}
		if(a[x-1][y]==0&&x-1>=0){
			a[x][y]=1;
			pop(q);
			x--;
			r(a,x,y,q);
			return;
		}
		if(a[x][y-1]==0&&y-1>=0){
			a[x][y]=1;
			pop(q);
			y--;
			r(a,x,y,q);
			return;
		}
	}
}

int main(){
	int a[5][5];
	int i,j,x,y;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		}
	}
	link *top;
	top=(link*)malloc(sizeof(link));
	top->head=(struct path*)malloc(sizeof(struct path));
	r(a,0,0,top);
	printf("(0, 0)\n");
	int PATH[25]={0};
	int count=0;
	while(top->head->next!=NULL){
		PATH[count]=top->head->x*10+top->head->y;
		count++;
		top->head=top->head->next;
	}
	for(i=count-1;i>=0;i--){
		printf("(%d, %d)\n",PATH[i]/10,PATH[i]%10);
	}
	return 0;
}
