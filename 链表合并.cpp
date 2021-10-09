#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		int a[m],b[n];
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		int p=0,q=0;
		while(p<m||q<n){
			if(p==m){
				cout<<b[q]<<" ";
				q++;
			}
			else if(q==n){
				cout<<a[p]<<" ";
				p++;
			}
			else{
				if(a[p]<=b[q]){
					cout<<a[p]<<" ";
					p++;
				}
				else{
					cout<<b[q]<<" ";
					q++;
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
