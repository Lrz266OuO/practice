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
    cout<<"The seqlist is: "<<endl;
    for(int i=1;i<=l.length;i++){
        cout<<l.r[i]<<" ";
    }
    cout<<endl;
}

void Direct_InsertSort(Seqlist &l){
    int i,j;
    for(i=2;i<=l.length;i++){
        l.r[0]=l.r[i];
        for(j=i-1;l.r[0]<l.r[j];j--){
            l.r[j+1]=l.r[j];
        }
        l.r[j+1]=l.r[0];
    }
}

void Binary_InsertSort(Seqlist &l){
    int low,high,mid,i,j;
    for(int i=2;i<=l.length;i++){
        l.r[0]=l.r[i];
        low=1;
        high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(l.r[mid]<l.r[0]) low=mid+1;
            else high=mid-1;
        }
        for(int k=i-1;k>=high+1;k--){
            l.r[k+1]=l.r[k];
        }
        l.r[high+1]=l.r[0];
    }
}

int main(){
    Seqlist l;
    Create(l);
    Output(l);
    Direct_InsertSort(l);
    Output(l);
    Binary_InsertSort(l);
    Output(l);
    return 0;
}