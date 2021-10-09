# include<stdio.h>
# include<malloc.h>
typedef struct
{
	int x;  
	int y;  
	int v;   
}Tri;

typedef struct
{
	Tri * data;
	int row; 
	int col; 
	int num; 
}Maxi;

void MaxiPrint(Maxi M); 
Maxi TransportFast(Maxi M);  

int main()
{
	Maxi M;
	int row, col, num;
	int i, x, y, v;
	printf("输入矩阵的大小 和 非0元素的个数：");
	scanf("%d%d%d", &row, &col, &num);

	M.row = row;
	M.col = col;
	M.num = num;
	M.data = (Tri *)malloc(sizeof(Tri) * num);

	printf("注意：输入的三元组先按行排列，再列排列\n");

	for(i = 0; i < num; i++)
	{
		printf("输入矩阵的第%d个三元组值x,y,v：", i+1);
		scanf("%d%d%d", &x, &y, &v);
		M.data[i].x = x;
		M.data[i].y = y;
		M.data[i].v = v;
	}
	MaxiPrint(M);

	Maxi F = TransportFast(M);
	MaxiPrint(F);

	return 0;
}

void MaxiPrint(Maxi M)
{
	int i, j, k;
	bool flag;
	for(i = 0; i < M.row; i++)
	{
		for(j = 0; j < M.col; j++)
		{
			flag = false;  //非0标记
			for(k = 0; k < M.num; k++)
			{
				if(i == M.data[k].x && j == M.data[k].y)
				{
					printf("%d ", M.data[k].v);
					flag = true;
					break;
				}
			}
			if(flag == false)
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
}


Maxi TransportFast(Maxi M)
{
	int i, q, col;
	Maxi T;
	T.row = M.col;
	T.col = M.row;
	T.num = M.num;
	T.data = (Tri *)malloc(sizeof(Tri) * T.num);

	int * num = (int *)malloc(sizeof(int) * M.col);

	for(i = 0; i < M.col; i++)  //初始化
	{
		num[i] = 0;
	}
	for(i = 0; i < M.num; i++)
	{
		num[M.data[i].y] ++;
	}

	int * index = (int *)malloc(sizeof(int) * T.row);
	index[0] = 0; 

	for(i = 1; i < T.row; i++)
	{
		index[i] = index[i - 1] + num[i - 1];
	}
	for(i = 0; i < M.num; i++)
	{
		 col = M.data[i].y;  
		 q = index[col];
		 T.data[q].x = M.data[i].y;
		 T.data[q].y = M.data[i].x;
		 T.data[q].v = M.data[i].v;
		 index[col] ++;
	}

	return T;

}
