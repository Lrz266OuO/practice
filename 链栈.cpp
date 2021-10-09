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
    LinkStack top = (LinkStack)malloc(sizeof(LinkStackNode));	
    top->next = NULL;	
    return top;
} 

int StackEmpty(LinkStack top){
    if(top->next==NULL) return 1;
    else return 0;
}

int Push(LinkStack top, StackElemType x){	
    LinkStackNode *temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));	
    if(temp == NULL){		
        return false;	
    }	
    temp->data = x;	
    temp->next = top->next;	
    top->next = temp;	
    return true;
} 

int Pop(LinkStack top, StackElemType *x){	
    LinkStackNode *temp;	
    temp = top->next;	
    if(temp == NULL){		
        return false;	
    }	
    top->next = temp->next;	
    *x = temp->data;	
    delete temp;	
    return true;
} 

int scan(){	
    int n;	
    cout << "Choose one step:" << endl;	
    cout << "1.Push    2.Pop" << endl;	
    cin >> n;	
    getchar();	
    return n;
} 

int GetTop(LinkStack top,StackElemType *e){
    LinkStackNode *p;
    p=top->next;
    if(!p){
        return 0;
    }
    *e=p->data;
    return 1;
}

int main(){	
    int quit = 0;	
    LinkStack top = CreateLinkStack();
	StackElemType x,e;	
    while(!quit){		
        switch(scan()){			
            case 1 : cout << "Please put in an element..." << endl;cin >> x;Push(top, x);break;			
            case 2 : if(Pop(top, &x))cout << x << " element is put out..." << endl;else cout << "None element!" << endl;break;			
            default: cout << "Put in failed!" << endl;quit = 1;		
        }	
    }

    if(GetTop(top,&e)==0){
        cout<<"The stack is empty!"<<endl;
    }
    else{
        cout<<"The top of stack is "<<e<<endl;
    }

    cout<<"Now the stack is: ";
    while(!StackEmpty(top)){
        Pop(top,&x);
        cout<<x<<" ";
    }
    cout<<endl;



return 0;
}
