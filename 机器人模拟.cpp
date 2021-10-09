#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	string str;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>str;
		x=0,y=0;
		for(int j=0;j<str.length();j++){
			if(str[j]=='W') y++;
			else if(str[j]=='S') y--;
			else if(str[j]=='D') x++;
			else x--;
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
