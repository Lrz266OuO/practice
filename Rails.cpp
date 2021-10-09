#include<cstdio>
#include<stack>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n),n){
		int a[1005];
		while(scanf("%d",&a[0]),a[0]){
			int i,k;
			for(i=1;i<n;i++){
				scanf("%d",&a[i]);
			}
			stack<int> s;
			for(i=1,k=0;i<=n;i++){
				s.push(i);
				while(s.top()==a[k]){
					if(!s.empty()){
						k++;
						s.pop();
					}
					if(s.empty()){
						break;
					}
				}
			}
			if(k==n) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
