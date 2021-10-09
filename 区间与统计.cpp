#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int n,p;
	int sum,num;
	for(int i=0;i<t;i++){
		num=0;
		cin>>n>>p;
		int a[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int j=0;j<n;j++){
			sum=0;
			for(int k=j;k<n;k++){
				sum+=a[k];
				if(sum==p){
					num++;
					break;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
} 
