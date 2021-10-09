#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long a[n],b[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		cin>>b[i];
	}
	long long max1=0,max2=0,len1,len2;
	for(long long i=0;i<n;i++){
		if(b[i]>max1){
			max1=b[i];
			len1=i;
		}
	}
	for(long long i=0;i<n;i++){
		if(b[i]>max2&&i!=len1){
			max2=b[i];
			len2=i;
		}
	}
	long long sum=0;
	for(long long i=0;i<n;i++){
		sum+=a[i];
	}
	if(sum<=max1+max2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
