#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int s[1000];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	int ans=0;
	for(int i=1;i<n-1;i++){
		for(int j=0;j<i;j++){
			int l=i,r=n-1;
			while(l<r){
				int mid=(l+r+1)/2;
				if(s[mid]>=s[i]+s[j]) r=mid-1;
				else l=mid;
			}
			ans+=l-i;
		}
	}
	printf("%d",ans);
	return 0;
}
