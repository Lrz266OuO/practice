#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string str1,str2;
	for(int i=0;i<n;i++){
		cin>>str1>>str2;
		string::size_type pos=str1.find(str2);
		if(pos==str1.npos){
			cout<<"-1"<<endl;
		}
		else cout<<pos<<endl;
	}
	return 0;
} 
