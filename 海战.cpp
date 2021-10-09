#include<iostream>
using namespace std;

int R,C;//R行  C列
char maps[1005][1005]={0};
char mapss[1005][1005]={0};//可以将maps全部原封不动的放进去，方便判断（注意范围）
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};//上下左右移动
int S=0;//连通块（个数）
int num=0;//判断船为矩形的合法性
int flag=1;//没啥用

void dfs(int x,int y,int flag)
{
	for(int i=0;i<4;i++)
	{
		//nx,ny为上下移动的结果
		int nx,ny==?
		
		if(判断合法)
		{
			//将maps[nx][ny]做上标记
			maps[nx][ny]=？
			dfs(nx,ny,？);	//重新dfs
		}
	}
	
	
}

bool check()//合法性的函数  在一个2*2的矩阵中，船的部分只能为0，1，2，4，不能为3（矩形总不能转弯吧，见上解释）

{
	num=0;
	for(int i=1;范围是什么？;i++)
	{
	num=0;
		for(int j=1;范围是什么？;j++)
		{
			num=0;
			//判断#在2*2方格中出现的次数
			if(mapss[i][j]=='#')num++;
			if(mapss[i+1][j]=='#')num++;
			if(mapss[i][j+1]=='#')num++;
			if(mapss[i+1][j+1]=='#')num++;
			if(？) return ？;//为3即不是矩形，返回假
		}
	}
	//否则返回真
	return ？;
	
}

int main(){
	
    cin>>R>>C;
    for(int i=1;i<=R;i++)
    {
    	for(int j=1;j<=C;j++)
    	{
    		cin>>maps[i][j];
    		mapss[i][j]=maps[i][j];
		}
	}
	
	if(check()==false)//根据check函数来判断
	{
		cout<<"Bad placement.";
		
	}
	else
	{
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
			{
				if(maps[i][j]=='#')
				{
					S++;
					maps[i][j]=？;
					//继续dfs
					dfs(i,j,？);
				}
			}
		}
		cout<<"There are "<<S<<" ships.";
	}
    
    return 0;
}

