#include<iostream>
using namespace std;
long long fastPower(long long base, long long exponent) {
    long long sum = 1;
    while (exponent != 0) {
        if ((exponent & 1) != 0) {
            sum *= base;
        }
        exponent = exponent >> 1;  
        base *= base; 
		base=base%10; 
		sum=sum%10;             
    }
    return sum;
}
int main(){
	int n;
	cin>>n;
	long long t;
	for(int i=0;i<n;i++){
		cin>>t;
		cout<<fastPower(t%10,t)<<endl;
	}
	return 0;
}
