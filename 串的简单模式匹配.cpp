#include<iostream>
#include<string>
using namespace std;

void StringMatch(string &t,string &p){
    int m=p.length();
    int n=t.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(t[i+j]!=p[j]) break;
        }
        if(j==m) cout<<"Pattern found at index: "<<i<<endl;
    }
}

int main(){
    string t,p;
    cin>>t>>p;
    StringMatch(t,p);

    return 0;
}