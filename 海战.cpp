#include<iostream>
using namespace std;

int R,C;//R��  C��
char maps[1005][1005]={0};
char mapss[1005][1005]={0};//���Խ�mapsȫ��ԭ�ⲻ���ķŽ�ȥ�������жϣ�ע�ⷶΧ��
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};//���������ƶ�
int S=0;//��ͨ�飨������
int num=0;//�жϴ�Ϊ���εĺϷ���
int flag=1;//ûɶ��

void dfs(int x,int y,int flag)
{
	for(int i=0;i<4;i++)
	{
		//nx,nyΪ�����ƶ��Ľ��
		int nx,ny==?
		
		if(�жϺϷ�)
		{
			//��maps[nx][ny]���ϱ��
			maps[nx][ny]=��
			dfs(nx,ny,��);	//����dfs
		}
	}
	
	
}

bool check()//�Ϸ��Եĺ���  ��һ��2*2�ľ����У����Ĳ���ֻ��Ϊ0��1��2��4������Ϊ3�������ܲ���ת��ɣ����Ͻ��ͣ�

{
	num=0;
	for(int i=1;��Χ��ʲô��;i++)
	{
	num=0;
		for(int j=1;��Χ��ʲô��;j++)
		{
			num=0;
			//�ж�#��2*2�����г��ֵĴ���
			if(mapss[i][j]=='#')num++;
			if(mapss[i+1][j]=='#')num++;
			if(mapss[i][j+1]=='#')num++;
			if(mapss[i+1][j+1]=='#')num++;
			if(��) return ��;//Ϊ3�����Ǿ��Σ����ؼ�
		}
	}
	//���򷵻���
	return ��;
	
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
	
	if(check()==false)//����check�������ж�
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
					maps[i][j]=��;
					//����dfs
					dfs(i,j,��);
				}
			}
		}
		cout<<"There are "<<S<<" ships.";
	}
    
    return 0;
}

