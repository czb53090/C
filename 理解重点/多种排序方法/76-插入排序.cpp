# include <stdio.h>
# include <stdlib.h>
# define N 6

/*
	2016年12月11日20:47:11
	实现方法：
		在n个数中，将第i个数插入到第i个数前面进行排序，
		以此类推直到i等于n时排序完成。
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
	int i, j, k, t;
	
	for (i=0; i<len; i++)
	{
		for (j=0; j<i; j++)
			if (a[i] < a[j])
			{
				t = a[i];
				for (k=i; k>j; k--)
					a[k] = a[k-1];
				a[j] = t;
				break;
			}
	}
}