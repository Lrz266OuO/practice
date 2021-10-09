#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int year;
	for(int i=0;i<n;i++){
		cin>>year;
		if(year%400==0||(year%4==0&&year%100!=0)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
