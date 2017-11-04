/*
	2016年11月14日14:56:00
	目的：
	给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上
	的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。找出A的鞍点。 
	例如：
		输入样例：
			4 
			1 7 4 1 
			4 8 3 6 
			1 6 1 2 
			0 7 8 9

		输出样例：
			2 1 
*/
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[100][100] = {0};
	int n, i, j, k, f=-1, w=-2, max, min, cnt=0;
	printf("假设矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。\n"); 
	printf("请给定一个n*n的矩阵A：n = ");
	scanf("%d", &n);

	//输入矩阵
	printf("请输入矩阵n*n中每个元素的值（以空格分隔，n个为一行）：\n");
	for (i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]); 

	//搜索鞍点
	printf("鞍点的坐标为（下标以0为起点）：\n"); 
	for (i=0; i<n; i++)
	{
		max = a[i][0];
		for(j=0; j<n-1; j++)
		{
			if (a[i][j+1] > max)
			{
				max = a[i][j+1];
				k = j+1;
				w = i;
			}
		}

		min = a[0][k];
		for (j=0; j<n-1; j++)
		{
			if (a[j+1][k] < min)
			{
				min = a[j+1][k];
				f = j+1;
			}	
		}
		if (w == f)
		{
			printf("（%d，%d）\n", w, k);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("No found!\n"); 

	system("pause");
	return 0;
}
