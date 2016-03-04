#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 101

int main()
{
	int solveProblem(int** M, int a, int b, int n);

	//变量
	int c;//表示c组数据
	int n, m, k;//n表示人数，m表示已知关系数目，k表示问题数目	
	int K[MAX_NUM][MAX_NUM];//K数组表示第l个组数据的第i个问题的解
	int l, i, j;
	//数据输入
	scanf("%d", &c);

	for (l = 0; l < c; ++l)//输入第l组数据
	{
		int M[MAX_NUM][MAX_NUM];//M数组表示关系，1代表有关系，0代表无关系

		scanf("%d %d %d", &n, &m, &k);
		if (n < 2 || n > 100)
		{
			exit(-1);
		}

		//对M,K数组置0
		for (i = 1; i <= n; ++i) 
		{
			for (j = 1; j <= n; ++j)	
			{
				M[i][j] = 0;
				K[i][j] = 0;
			}
		}
		//关系输入
		for (i = 0; i < m; ++i)
		{
			int a, b;//a, b用于表示存在关系

			scanf("%d %d", &a, &b);
			if (a == b)
			{
				M[a][b] = 0;
			}
			else
			{
				M[a][b] = 1;
				M[b][a] = 1;
			}
		}
		//问题输入
		for (i = 0; i < k; ++i)
		{	
			int a, b, h;//a, b用于表示存在问题
			int* p[n+1];
			for (h = 0; h <= n; ++h)
			{
				p[h] = M[h];
			}

			scanf("%d %d", &a, &b);
			//解决问题
			if (a == b)
			{
				K[l][i] = 0;
			}
			else
			{
				K[l][i]  = solveProblem(p, a, b, n);//K数组表示第l个组数据的第i个问题的解
			}
		}
	}

	//答案统一输出
	for (l = 0; l < c; ++l)
	{
		printf("Case %d:\n", l+1);
		for (i = 0; i < k; ++i)
		{
			printf("%d\n", K[l][i]);
		}
	}

	return 0;
}

int solveProblem(int** M, int a, int b, int n)
{
	int num = 0;
	int i;
	// 遍历m数组的第a行和第b行，寻找两行中同时为1的个数
	for (i = 1; i <= n; ++i)
	{
		if (M[a][i]==1 && M[b][i]==1)
		{
			++num;
		}
	}
	return num;
}