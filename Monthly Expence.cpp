#include<iostream>
#include<cstdio>
using namespace std;
int a[100010];
int main(){
	int m,n,l=0,r=0,mid;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(l<a[i]) l=a[i];
		r+=a[i];
	}
	while(l<=r){
		int sum=0,cnt=1;
		mid=(l+r)>>1;
		for(int i=0;i<n;i++){
			if(sum+a[i]<=mid) sum+=a[i];
			else{
				sum=a[i];
				cnt++;
			}
		}
		if(cnt<=m) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
