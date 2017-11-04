# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j, k, n, p;
	int a[16][16];

	printf("输入一个在3~15的奇数n，算出在n*n的魔方阵中，\n每一行.每一列和对角线之和均相等。\n");
	//判断阶数是否为1~15的奇数
	p = 1;
	while (p == 1)
	{
		printf("enter number n(n=1~15):");
		scanf("%d", &n);
		if ((n>2) && (n<16) && (n%2!=0))
			p = 0;
	}
	
	//初始化a
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			a[i][j] = 0;

	//建立魔方阵
	j = n/2+1;
	a[1][j] = 1;
	for (k=2; k<=n*n; k++)
	{
		i--;
		j++;
		if (i<1 && j>n) //当上一数为第1行最后一个时
		{
			i+=2;
			j--;
		}
		else
		{
			if (i < 1)
				i = n;
			if (j > n)
				j = 1;
		}
		if (a[i][j] == 0)
			a[i][j] = k;
		else
		{
			i+=2;
			j--;
			a[i][j] = k;
		}
	}

	//输出魔方阵
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}
