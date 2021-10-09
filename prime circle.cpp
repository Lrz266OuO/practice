#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int num[100100],vis[100100];
int n;
int prim(int x)//x是否为素数
{
    for(int i=2;i*i<=x;i++)
    if(x%i==0)
    return 0;
    return 1;
}
void dfs(int c)//从1开始搜索
{
    if(c==n&&prim(num[n-1]+1))//如果排到了最后一位且与第一位的和满足条件
    {
        printf("1");//保证第一位是1；
        for(int i=1;i<n;i++)//实际从num[]的第二位输出
        printf(" %d",num[i]);//一直到n-1位
        printf("\n");
    }
    if(c==n) return ;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&prim(num[c-1]+i))//满足与上一位和为素数，且数字没有被使用过
        {
            num[c]=i;//放入这个满足条件的数
            vis[i]=1;//标记
            dfs(c+1);//搜索下一位
            vis[i]=0;
        }
    }
}
int main()
{
    int k=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));//每一次的n，都要讲标记数组清零
        num[0]=1;
        vis[1]=1;//标记1被使用
        printf("Case %d:\n",k++);
        dfs(1);
        printf("\n");
    }
    return 0;
}
 
