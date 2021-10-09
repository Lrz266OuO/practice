#include<iostream>
using namespace std;
bool Run(int y){
	if(y%400==0||(y%4==0&&y%100!=0)) return true;
	else return false;
}
int main(){
	int n;
	cin>>n;
	int y,m,d;
	int ping[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	int run[12]={0,31,60,91,121,152,182,213,244,274,305,335};
	for(int i=0;i<n;i++){
		cin>>y>>m>>d;
		if(Run(y)) cout<<run[m-1]+d<<endl;
		else cout<<ping[m-1]+d<<endl;
	}
	return 0;
} 
