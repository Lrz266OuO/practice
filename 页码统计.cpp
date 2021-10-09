#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x;
	int num[10];
	int k; 
	for(int i=0;i<n;i++){
		cin>>x;
		for(int j=0;j<10;j++){
			num[j]=0;
		}
		for(int j=1;j<=x;j++){
			k=j;
			while(k){
				num[k%10]++;
				k=k/10;
			}
		}
		for(int j=0;j<10;j++){
			cout<<num[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
