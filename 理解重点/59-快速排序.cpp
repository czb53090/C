/*
	2016��12��11��22:31:08
	2016��12��11��22:41:38
*/

# include <stdio.h>
# include <stdlib.h>
# define N 6

void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main(void)
{
	int a[N];
	int i;

	printf("������%d���������п�������:\n", N);
	for (i=0; i<N; i++)
		scanf("%d", &a[i]);

	QuickSort(a, 0, N-1);

	for (i=0; i<N; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
	return 0;
}

void QuickSort(int * a, int low, int high)
{
	int pos;

	if (low < high)
	{
		pos = FindPos(a, low, high);
		//�ֳ�������ң���posλ������Һ��ұ���
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
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