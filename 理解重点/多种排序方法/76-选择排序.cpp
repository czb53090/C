# include <stdio.h>
# include <stdlib.h>
# define N 6

/*
	2016年12月11日20:31:10
	实现方法：
		从n个数中找到最小的数与第1个数互换，
		再从剩下的n-1个数中找到最小的数于第2个数互换，
		以此类推。
*/

void sort(int * a, int len);

int main(void)
{
	int a[N];
	int i;

	printf("请输入%d个整数进行排序（由小到大）:\n", N);
	for (i=0; i<N; i++)
		scanf("%d", &a[i]);
	sort(a, N);

	for (i=0; i<N; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
	return 0;
}

void sort(int * a, int len)
{
	int i, j, min, t;

	for (i=0; i<len-1; i++)
	{
		for (j=i+1,min=i; j<len; j++)
			if (a[min] > a[j])
				min = j;
		t = a[i];
		a[i] = a[min];
		a[min] = t;
	}
}