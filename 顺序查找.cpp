#include<iostream>
using namespace std;

int SequenceSearch(int a[],int value,int n){
    a[0]=value;
    for(int i=n;i>=0;i--){
        if(a[i]==value) return i;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<n+1;i++){
        cin>>a[i];
    }
    int value[2]={21,85};
    cout<<SequenceSearch(a,value[0],n)<<" "<<SequenceSearch(a,value[1],n)<<endl;

    return 0;
}