#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[100001];
int main(){
    int letter[26]={0};
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        letter[str[i]-'a']++;
    }
    for(int i=0;i<len;i++){
        if(letter[str[i]-'a']==1){
            cout<<str[i]<<endl;
            return 0;
        }
    }
    cout<<"no"<<endl;
    return 0;
}