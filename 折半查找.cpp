#include<iostream>
using namespace std;

int BinarySearch(int a[],int value,int n,int &visit){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        visit++;
        if(value==a[mid]) return mid;
        else if(value>a[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int visit=0;
    cout<<BinarySearch(a,21,11,visit)<<" "<<visit<<endl;

    visit=0;
    cout<<BinarySearch(a,85,11,visit)<<" "<<visit<<endl;

    return 0;
}