#include<iostream>
#include<queue>
using namespace std;
int main(){
	int t,n,k,temp;
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>k;
		queue<int> q;
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		while(q.size()!=1){
			for(int i=0;i<k-1;i++){
				temp=q.front();
				q.push(temp);
				q.pop();
			}
			q.pop();
		}
		cout<<"Case "<<j<<": "<<q.front()<<endl;
	}
	return 0;
} 
