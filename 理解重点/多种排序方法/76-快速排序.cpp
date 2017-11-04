# include <stdio.h>
# include <stdlib.h>
# define N 6

void Quicksort(int * a,int low, int high);
int FindPos(int * a, int low, int high);

int main(void)
{
	int a[N];

	int i;
	
	printf("请输入%d个整数进行排序（由小到大）:\n", N);
	for (i=0; i<N; i++)
		scanf("%d", &a[i]);
	Quicksort(a, 0, N-1); //第二个参数表示第一个元素的下标，第三个元素表示最后一个元素的下标
	
	for (i=0; i<N; i++)
		printf("%d ", a[i]);
	printf("\n");

	
	system("pause");
	return 0;
}

void Quicksort(int * a,int low, int high)
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
	//终止while循环之后low和high一定是相等的，low == high
	a[low] = val;
	return low;
}