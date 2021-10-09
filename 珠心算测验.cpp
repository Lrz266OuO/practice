#include<bits/stdc++.h>
using namespace std;
bool mark[1500];
long long a[1500];
int main(){
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long t=a[i]+a[j];
			long long pos=lower_bound(a+1,a+n+1,t)-a;
			if(pos<=n&&a[pos]==t) mark[pos]=true;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=mark[i];
	} 
	cout<<ans<<endl;
	return 0;
}
