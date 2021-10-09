#include<iostream>
#include<cstdio>
#define Maxsize 100
using namespace std;
typedef int KeyType;
typedef struct{
    KeyType r[Maxsize];
    int length;
}Seqlist;

void Create(Seqlist &l){
    cout<<"Please input the length of the seqlist: ";
    scanf("%d",&l.length);
    if(l.length==0) return;
    cout<<"Please input the data of the seqlist: ";
    for(int i=1;i<=l.length;i++){
        scanf("%d",&l.r[i]);
    }
}

void Output(Seqlist l){
    cout<<"At this time, the seqlist is: "<<endl;
    for(int i=1;i<=l.length;i++){
        cout<<l.r[i]<<" ";
    }
    cout<<endl;
}

int Partition(Seqlist &l,int low,int high){
    l.r[0]=l.r[low];
    int pivotkey=l.r[low];
    while(low<high){
        while(low<high&&l.r[high]>=pivotkey){
            --high;
        }
        l.r[low]=l.r[high];
        while(low<high&&l.r[low]<=pivotkey){
            ++low;
        }
        l.r[high]=l.r[low];
    }
    l.r[low]=l.r[0];
    return low;
}

void Quick_Sort(Seqlist &l,int low,int high){
    if(low<high){
        int pivotloc=Partition(l,low,high);
        Output(l);
        Quick_Sort(l,low,pivotloc-1);
        Quick_Sort(l,pivotloc+1,high);
    }
}

int main(){
    Seqlist l;
    Create(l);
    Output(l);
    Quick_Sort(l,1,l.length);
    Output(l);

    return 0;
}