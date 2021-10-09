#include<bits/stdc++.h>
using namespace std;
void BackOrder(char *PreOrder,char *InOrder,int len){
	if(len==0){
		return;
	}	
	char Node=*PreOrder;
	int root;
	for(root=0;root<len;root++){
		if(InOrder[root]==Node){
			break;
		}
	}
	BackOrder(PreOrder+1,InOrder,root);
	BackOrder(PreOrder+root+1,InOrder+root+1,len-(root+1));
	cout<<Node;
	return;
}

int main(){
	char a[10000],b[10000];
	while(~scanf("%s%s",a,b)){
		int len=strlen(a);
		BackOrder(a,b,len);
		cout<<endl;
	}
	return 0;
} 
