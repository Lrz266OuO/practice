#include<bits/stdc++.h>
using namespace std;
float cal(char a,float b,float c){
	switch(a){
		case '+':
			return b+c;
			break;
		case '-':
			return b-c;
			break;
		case '*':
			return b*c;
			break;
		case '/':
			return b*1.0/c;
			break;
	}
}

int main(){
	float stack1[200];
	char stack2[100];
	int top1=-1,top2=-1;
	int i;
	string str;
	char a;
	float b,c;
	
	int t;
	cin>>t;
	while(t--){
		cin>>str;
		for(i=0;i<str.length();i++){
			if(str[i]=='+'||str[i]=='-'){
				if(top2==-1) stack2[++top2]=str[i];
				else{
					while(stack2[top2]=='+'||stack2[top2]=='-'||stack2[top2]=='*'||stack2[top2]=='/'){
						a=stack2[top2--];
						c=stack1[top1--];
						b=stack1[top1--];
						stack1[++top1]=cal(a,b,c);
						
					}
					stack2[++top2]=str[i];
				}
			}
			else if(str[i]=='*'||str[i]=='/'){
				if(top2==-1) stack2[++top2]=str[i];
				else{
					while(stack2[top2]=='*'||stack2[top2]=='/'){
						a=stack2[top2--];
						c=stack1[top1--];
						b=stack1[top1--];
						stack1[++top1]=cal(a,b,c);
					}
					stack2[++top2]=str[i];
				}
			}
			else{
				stack1[++top1]=str[i]-'0';
			}
		}
		while(top2!=-1){
			a=stack2[top2--];
			c=stack1[top1--];
			b=stack1[top1--];
			stack1[++top1]=cal(a,b,c);
		}
		printf("%4f\n",stack1[top1]);
	}
	return 0;
}
