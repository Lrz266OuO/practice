#include<iostream>
#include<queue>
using namespace std;
typedef struct
{
	int step;
	int floor;
} dt;
queue<dt>lift;//������� 
bool flag[2000],f;
int main()
{
	int n,a,b,k[2000];//k��i����ʾ��i���������/�½�����¥ 
	dt s,e;//������dt���͵�s,e����������ʾ���㣬�յ�� 
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	//��ʼ����������a¥ 
	s.step =0;s.floor =a;
	lift.push(s);//��¥��� 
	//�����еķ���ûʵ���꣬Ҳ���Ƕ��в�Ϊ��ʱ������ 
	while(!lift.empty())
	{
		s=lift.front();//ÿ��������¥���˰������� 
		lift.pop() ;//�߹���¥�㣨������Ŀ����ԣ����Գ����� 
		if(s.floor ==b)//�ߵ��˹涨¥�� 
		{
			cout<<s.step<<endl;
			f=1;
			break;
		}
		//��������� 
		if(s.floor +k[s.floor]<=n&&!flag[s.floor+k[s.floor]])//���¥���ڷ�Χ����û���߹� 
		{
			e.floor =s.floor+k[s.floor];
			e.step =s.step +1;
			flag[e.floor]=1;
			lift.push(e); 
		}
		//�½������ 
		if(s.floor -k[s.floor]>=1&&!flag[s.floor-k[s.floor]])
		{
			e.floor =s.floor-k[s.floor];
			e.step =s.step +1;
			flag[e.floor]=1;
			lift.push(e); 
		}
	}
	if(f==0)	cout<<"-1"<<endl; 
	return 0;
} 
