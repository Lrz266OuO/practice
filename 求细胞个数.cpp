#include<bits/stdc++.h>
using namespace std;
int gx[4]={-1,0,1,0},gy[4]={0,1,0,-1};
int a[110][110],tot=0,n,m;

void init(){
	string s;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='0') a[i][j+1]=0;
			else a[i][j+1]=1;
		}
	}
}

void work(int x,int y){
	queue<int> qx,qy;
	int x1,y1;
	tot++;
	qx.push(x);
	qy.push(y);
	a[x][y]=0;
	while(!qx.empty()){
		for(int i=0;i<4;i++){
			x1=qx.front()+gx[i];
			y1=qy.front()+gy[i];
			if(x1>0&&x1<=m&&y1>0&&y1<=n&&a[x1][y1]){
				qx.push(x1);
				qy.push(y1);
				a[x1][y1]=false;
			}
		}
		qx.pop();
		qy.pop();
	}
}

int main(){
	init();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]) work(i,j);
		}
	}
	cout<<tot<<endl;
	return 0;
}
