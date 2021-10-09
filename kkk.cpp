#include<iostream>
using namespace std;
int main(){
	short int x=12345;
	unsigned short int ux=(unsigned short)x;
	short int y=-12345;
	unsigned short int uy=(unsigned short)y;
	cout<<ux<<uy<<endl;
	return 0;
}