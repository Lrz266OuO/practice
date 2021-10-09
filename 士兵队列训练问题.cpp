#include<bits/stdc++.h>
using namespace std;
#define N 5002 
struct Q{
	int f,r,da[N];
	void init(){
		f=0,r=0;
	}
	void push(int a){
		da[r++]=a;
	}
	int gettop(){
		return da[f++];
	}
	bool ch(){
		return r-f<4;
	}
	bool empty(){
		return f==r;
	}
}q[2];
int main(){
	int t,n,i;
	cin>>t;
	while(t--){
		cin>>n;
		q[0].init();
		q[1].init();
		for(i=1;i<=n;i++){
			q[0].push(i);
		}
		int now=0,pre=1;
		i=0;
		while(!q[now].ch()){
			q[pre].init();
			if(i&1){
				while(!q[now].empty()){
					q[pre].push(q[now].gettop());
					if(q[now].empty()) break;
					q[pre].push(q[now].gettop());
					if(q[now].empty()) break;
					q[now].gettop();
				}
			}
			else{
				while(!q[now].empty()){
					q[pre].push(q[now].gettop());
					if(q[now].empty()) break;
					q[now].gettop();
				}
			}
			i=i^1;
			swap(now,pre);
		}
		cout<<q[now].gettop();
		while(!q[now].empty()){
			cout<<" "<<q[now].gettop();
		}
		cout<<endl;
	}
	return 0;
}
