#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int num[100100],vis[100100];
int n;
int prim(int x)//x�Ƿ�Ϊ����
{
    for(int i=2;i*i<=x;i++)
    if(x%i==0)
    return 0;
    return 1;
}
void dfs(int c)//��1��ʼ����
{
    if(c==n&&prim(num[n-1]+1))//����ŵ������һλ�����һλ�ĺ���������
    {
        printf("1");//��֤��һλ��1��
        for(int i=1;i<n;i++)//ʵ�ʴ�num[]�ĵڶ�λ���
        printf(" %d",num[i]);//һֱ��n-1λ
        printf("\n");
    }
    if(c==n) return ;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&prim(num[c-1]+i))//��������һλ��Ϊ������������û�б�ʹ�ù�
        {
            num[c]=i;//�������������������
            vis[i]=1;//���
            dfs(c+1);//������һλ
            vis[i]=0;
        }
    }
}
int main()
{
    int k=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));//ÿһ�ε�n����Ҫ�������������
        num[0]=1;
        vis[1]=1;//���1��ʹ��
        printf("Case %d:\n",k++);
        dfs(1);
        printf("\n");
    }
    return 0;
}
 
