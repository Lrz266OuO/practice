#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x;
	long long a[60];
	for(int i=0;i<n;i++){
		cin>>x;
		a[0]=0;
		a[1]=1;
		for(int j=2;j<=x;j++){
			a[j]=a[j-1]+a[j-2];
		}
		cout<<a[x]<<endl;
	}
	return 0;
}
