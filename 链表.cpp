#include<iostream>
#include<cstdlib>
using namespace std;

struct ListNode{
    int key;
    ListNode *next;
};

void CreateList(ListNode *pHead){
    ListNode *p=pHead;
    for(int i=1;i<10;++i){
        ListNode *pNewNode=new ListNode;
        pNewNode->key=i;
        pNewNode->next=NULL;
        p->next=pNewNode;
        p=pNewNode;
    }
}

void PrintList(ListNode *pHead){
    ListNode *p=pHead;
    while(p){
        cout<<p->key<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    ListNode *head=NULL;
    head=new ListNode;
    head->key=0;
    head->next=NULL;
    CreateList(head);
    PrintList(head);

    return 0;
}