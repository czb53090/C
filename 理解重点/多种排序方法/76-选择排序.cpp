# include <stdio.h>
# include <stdlib.h>
# define N 6

/*
	2016��12��11��20:31:10
	ʵ�ַ�����
		��n�������ҵ���С�������1����������
		�ٴ�ʣ�µ�n-1�������ҵ���С�����ڵ�2����������
		�Դ����ơ�
*/

void sort(int * a, int len);

int main(void)
{
	int a[N];
	int i;

	printf("������%d����������������С����:\n", N);
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