/*
	Ŀ�ģ�n����Χ��һȦ�������źš��ӵ�1���˿�ʼ��������1��3����)��
		  ������3�����˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ��
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int n, i, k, m;
	int a[50];

	printf("input number of person:");
	scanf("%d", &n);

	// ��ÿ��������
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

