#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack_Sq(SqStack &s){
	s.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!s.base){
		printf("分配失败\n");
		return 0;
	}
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return 1;
}

int Push(SqStack &s,SElemType e){
	if(s.top-s.base>=s.stacksize){
		s.base=(SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!s.base) return 0;
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*(s.top)=e;
	s.top++;
	return 1;
}

int GetTop_Sq(SqStack s,SElemType &e){
	if(s.top==s.base) return 0;
	e=*(s.top-1);
	return 1;
}

int Pop(SqStack &s,SElemType &e){
	if(s.top==s.base) return 0;
	e=*(--s.top);
	return 1;
}

int PrintStack(SqStack s){
	if(s.base==NULL) return 0;
	if(s.top==s.base) printf("No number");
	SElemType *p;
	p=s.top;
	while(p>s.base){
		p--;
		printf("%d ",*p);
	}
	return 1;
}

int main(){
	int n,k;
	SqStack s;
	InitStack_Sq(s);

	printf("Please put in the number of Stack: ");
	scanf("%d",&n);
	printf("Please put in the element of stack: ");
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		Push(s,k);
	}
	printf("Now the stack is: ");
	PrintStack(s);
	printf("\n");

	int a;
	printf("Please put in a number: ");
	scanf("%d",&a);
	Push(s,a);
	printf("Now the stack is: ");
	PrintStack(s);
	printf("\n");
	
	int e;
	GetTop_Sq(s,e);
	printf("The top of stack is ");
	printf("%d\n",e);

	int b;
	Pop(s,b);
	printf("Now the stack is: ");
	PrintStack(s);
	printf("\n");

	return 0;
}