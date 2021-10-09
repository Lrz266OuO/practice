#include<bits/stdc++.h>
using namespace std;
stack<string> s1,s2;
int main(){
	string w="http://www.acm.org/";
	string h,temp;
	while(cin>>h&&h!="QUIT"){
		if(h=="VISIT"){
			s1.push(w);
			cin>>w;
			cout<<w<<endl;
			while(!s2.empty()){
				s2.pop();
			}
		}
		else if(h=="BACK"){
			if(s1.empty()){
				cout<<"Ignored"<<endl;
			}
			else{
				cout<<s1.top()<<endl;
				s2.push(w);
				w=s1.top();
				s1.pop();
			}
		}
		else if(h=="FORWARD"){
			if(s2.empty()){
				cout<<"Ignored"<<endl;
			}
			else{
				cout<<s2.top()<<endl;
				s1.push(w);
				w=s2.top();
				s2.pop();
			}
		}
	}
	return 0;
}
