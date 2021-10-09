#include<iostream>
#include<string.h>
using namespace std;

void call_next(char str[],int next[],int len){
    next[0]=-1;
    int k=-1;
    for(int i=1;i<len;i++){
        while(k>-1&&str[k+1]!=str[i]){
            k=next[k];
        }
        if(str[k+1]==str[i]){
            k++;
        }
        next[i]=k;
    }
}

int KMP(char str[],int slen,char ptr[],int plen){
    int next[plen];
    call_next(ptr,next,plen);
    int k=-1;
    for(int i=0;i<slen;i++){
        while (k>-1&&ptr[k+1]!=str[i])
        {
            k=next[k];
        }
        if(ptr[k+1]==str[i]) k++;
        if(k==plen-1) return i-plen+1;
    }
    return -1;
}

int main(){
    int m,n;
    cin>>m>>n;
    char str[m];
    char ptr[n];
    for(int i=0;i<m;i++){
        cin>>str[i];
    }
    for(int i=0;i<n;i++){
        cin>>ptr[i];
    }
    cout<<"Pattern found at index: "<<KMP(str,strlen(str),ptr,strlen(ptr))<<endl;
    return 0;
}