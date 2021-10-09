#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	int n;
	while(cin>>str){
		n=0;
		for(int i=0;i<str.length();i++){
			if(str[i]=='(') n++;
			else if(str[i]==')') n--;
			else{
				break;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
