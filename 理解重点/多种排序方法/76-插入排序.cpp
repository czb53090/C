# include <stdio.h>
# include <stdlib.h>
# define N 6

/*
	2016��12��11��20:47:11
	ʵ�ַ�����
		��n�����У�����i�������뵽��i����ǰ���������
		�Դ�����ֱ��i����nʱ������ɡ�
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