#include<iostream>
using namespace std;
int main(){
	int n,t;
	cin>>n;
	int a[4][13];
	int A,B;
	int sum;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<4;j++){
			for(int k=0;k<13;k++){
				a[j][k]=1;
			}
		}
		cin>>t;
		for(int j=0;j<t;j++){
			cin>>A>>B;
			a[A-1][B-1]=0;
		}
		for(int j=0;j<11;j++){
			for(int q=0;q<4;q++){
				for(int w=0;w<4;w++){
					for(int e=0;e<4;e++){
						if(a[q][j]==1&&a[w][j+1]==1&&a[e][j+2]==1) sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
