#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int ans=a/b;
	int n=a%b;
	for(int i=0;i<b-n;i++){
		cout<<ans<<" ";
	}
	for(int i=0;i<n;i++){
		cout<<ans+1<<" ";
	}
	cout<<endl;
	return 0;
} 
