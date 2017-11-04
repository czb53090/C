/*
	2016年12月12日15:33:44
	2016年12月12日15:42:02
*/

# include <stdio.h>
# include <stdlib.h>
# define N 6

void Quicksort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main(void)
{
	int a[N];
	int i;

	printf("请输入%d个整数进行快速排序（由小到大）：\n", N);
	for (i=0; i<N; i++)
		scanf("%d", &a[i]);

	Quicksort(a, 0, N-1);

	for (i=0; i<N; i++)
		printf("%d ", a[i]);

	system("pause");
	return 0;
}

void Quicksort(int * a, int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = FindPos(a, low, high);
		Quicksort(a, low, pos-1);
		Quicksort(a, pos+1, high);
	}
}
int FindPos(int * a, int low, int high)
{
	int val = a[low];
	while (low < high)
	{
		while (low<high && a[high]>=val)
			high--;
		a[low] = a[high];
		while (low<high && a[low]<=val)
			low++;
		a[high] = a[low];
	}
	a[low] = val;
	return low;
}