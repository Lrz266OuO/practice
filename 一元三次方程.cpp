#include<iostream>
using namespace std;

int main(){
    int k;
    cin>>k;
    double n=1;
    double sum=0;
    while(sum<=k){
        sum+=1.0/n;
        n++;
    }
    cout<<n-1<<endl;
    return 0;
}