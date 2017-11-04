/*
	目的：n个人围成一圈，排序排号。从第1个人开始报数（从1到3报数)，
		  凡报道3的人退出圈子，问最后留下的是原来第几号的那位。
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int n, i, k, m;
	int a[50];

	printf("input number of person:");
	scanf("%d", &n);

	// 给每个人排序
	for (i=0; i<n; i++)
		a[i] = i + 1;

	i = k = m = 0;
	while (m < n-1)
	{
		if (a[i] != 0)
			k++;
		if (k == 3)
		{
			a[i] = 0;
			m++;
			k=0;
		}

		i++;
		if (i == n)
			i = 0;
	}

	i = 0;
	while(a[i++] == 0);

	printf("The final number is:%d\n", a[i-1]);

	system("pause");
	return 0;
}

