#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef char StackElemType;
typedef struct LinkStackNode{
	StackElemType data;	
    struct LinkStackNode *next;
}LinkStackNode, *LinkStack; 

LinkStack CreateLinkStack(){	
    LinkStack p = (LinkStack)malloc(sizeof(LinkStackNode));	
    p->next = NULL;	
    return p;
} 

int StackEmpty(LinkStack p){
    if(p->next==NULL) return 1;
    else return 0;
}

int Push(LinkStack p, StackElemType x){	
    LinkStackNode *temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));	
    if(temp == NULL){		
        return false;	
    }	
    temp->data = x;	
    temp->next = p->next;	
    p->next = temp;	
    return true;
} 

int Pop(LinkStack p, StackElemType *x){
    LinkStackNode *temp;	
    temp = p->next;	
    if(temp == NULL){		
        return false;	
    }	
    p->next = temp->next;	
    *x = temp->data;	
    delete temp;	
    return true;
} 

int Pop_as_Queue(LinkStack p, StackElemType *x){
    StackElemType e;
    LinkStack q=CreateLinkStack();
    while(!StackEmpty(p)){
        Pop(p,&e);
        Push(q,e);
    }
    *x=e;
    Pop(q,&e);
    while(!StackEmpty(q)){
        Pop(q,&e);
        Push(p,e);
    }

    return 1;
}

int scan(){	
    int n;	
    cout << "Choose one step:" << endl;	
    cout << "1.Push    2.Pop" << endl;	
    cin >> n;	
    getchar();	
    return n;
} 

int main(){	
    int quit = 0;	
    LinkStack p = CreateLinkStack();
	StackElemType x,e;	
    while(!quit){		
        switch(scan()){			
            case 1 : cout << "Please put in an element..." << endl;cin >> x;Push(p, x);break;			
            case 2 : if(Pop_as_Queue(p,&x))cout << x << " element is put out..." << endl;else cout << "None element!" << endl;break;			
            default: cout << "Put in failed!" << endl;quit = 1;		
        }	
    }

    cout<<"Now the stack is: ";
    while(!StackEmpty(p)){
        Pop(p,&x);
        cout<<x<<" ";
    }
    cout<<endl;

return 0;
}