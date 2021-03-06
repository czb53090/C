/*
	魔方阵：它的每一行.每一列和对角线之和均相等
	例子：
			8	1	6
			3	5	7
			4	9	2
	步骤：
	(1) 将1放在第1行中间一列

	(2) 从2开始直到n*n止各数依次按下列规则存放：每一个数存放的行比
		前一个数的行数减1，列数加1（例如上面的三阶魔方阵，5在4的上
		一行后一列）

	(3) 如果上一数的行数为1，则下一个数的行数为n（指最下一行）。例
		如，1在第1行，则2应放在最下一行，列数同样加1。

	(4) 当上一个数的列数为n时，下一个数的列数应为1，行数减1。例如，
		2在第3行最后一列，则3应放在第2行第1列。

	(5) 如果按上面规则确定的位置上已有数，或上一个数是第1行第n列时，
		则把下一个数放在上一个数的下面。例如，按上面的规定，4应该放
		在第1行第2列，但该位置已被1占据，所以4就放在3的下面。由于6
		是第1行第3列（即最后一列），故7放在6下面。
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j, k, p, n;
	int a[15][15];

	//要求阶数为3~15之间的奇数
	p = 1;
	while (p == 1)
	{
		printf("enter n(n = 1~15):");
		scanf("%d", &n);
		if ((n!=0) && (n<=15) && (n%2!=0) && (n!=1))
			p = 0;
	}

	//初始化
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
		if((i<1) && (j>n))
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
