#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int x;
	int y;
	int step;   //��¼����
};
int n, m, x, y;
int map[410][410];
int X[8] = { 1,-1,2,-2,2,-2,1,-1 };   //8������
int Y[8] = { 2,2,1,1,-1,-1,-2,-2 };
bool judge(int p, int q)              //�ж��Ƿ����
{
	if (p<1 || p>n || q<1 || q>m)
		return false;
	else if (map[p][q] != -1)
		return false;
	else
		return true;
}
void BFS()
{
	queue<node> q;
	node t1 = { x,y,0 };
	q.push(t1);
	map[x][y] = 0;    //��Ҫ�������
	while (!q.empty())
	{
		t1 = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			if (judge(t1.x + X[i], t1.y + Y[i]))
			{
				node t2 = { t1.x + X[i], t1.y + Y[i],t1.step + 1 };
				q.push(t2);
				map[t2.x][t2.y] = t2.step;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 410; i++)
		for (int j = 0; j < 410; j++)
			map[i][j] = -1;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	BFS();
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= m; j++)     //ע�������ʽ
			printf("%d ", map[i][j]);   //����룬��5��
		printf("\n");
	}
	return 0;
}

