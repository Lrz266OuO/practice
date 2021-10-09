#include<iostream>
using namespace std;
int main(){
	int a[7]={100,50,20,10,5,2,1};
	int c[7];
	int n;
	int k;
	int sum,paper;
	bool success;
	cin>>n;
	for(int i=0;i<n;i++){
		success=false;
		paper=0;
		sum=0;
		cin>>k;
		for(int j=6;j>=0;j--){
			cin>>c[j];
		}
		for(int j=0;j<7;j++){
			while(c[j]>0){
				c[j]--;
				sum+=a[j];
				paper++;
				if(sum==k){
					cout<<paper<<endl;
					success=true;
					break;
				}
				if(sum>k){
					c[j]++;
					sum-=a[j];
					paper--;
					break;
				}
			}
			if(success==true) break;
		}
		if(success==false) cout<<"-1"<<endl;
	}
	return 0;
} 
