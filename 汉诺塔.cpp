#include<iostream>
using namespace std;
int main(){
	int n;
	long long a[40];
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		a[0]=1;
		a[1]=2;
		for(int j=2;j<=x;j++){
			a[j]=a[j-1]*2;
		}
		cout<<a[x]-1<<endl;
	}
	return 0;
}
