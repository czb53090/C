# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[11] = {2, 3, 23, -8, -1, 0, 5, 22, 10, 55};
	int i, j, t, x;

	//���
	for (i=0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");

	//����--�ɴ�С
	printf("�����Ϊ��\n");
	for (i=0; i<10; i++)
		for (j=0; j<9-i; j++)
			if (a[j] < a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	//���
	for (i=0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");

	
	//����һ����������������
	printf("������һ������Ҫ�������ֵ��");
	scanf("%d", &x);
	a[10] = x;
	for (i=0; i<11; i++)
	{
		for (j=9; j>=i; j--)
		{
			if (a[j] < a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
			
		}
	}

	//���
	for (i=0; i<11; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
	return 0;
}
