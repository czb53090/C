# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j, k, n, p;
	int a[16][16];

	printf("����һ����3~15������n�������n*n��ħ�����У�\nÿһ��.ÿһ�кͶԽ���֮�;���ȡ�\n");
	//�жϽ����Ƿ�Ϊ1~15������
	p = 1;
	while (p == 1)
	{
		printf("enter number n(n=1~15):");
		scanf("%d", &n);
		if ((n>2) && (n<16) && (n%2!=0))
			p = 0;
	}
	
	//��ʼ��a
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			a[i][j] = 0;

	//����ħ����
	j = n/2+1;
	a[1][j] = 1;
	for (k=2; k<=n*n; k++)
	{
		i--;
		j++;
		if (i<1 && j>n) //����һ��Ϊ��1�����һ��ʱ
		{
			i+=2;
			j--;
		}
		else
		{
			if (i < 1)
				i = n;
			if (j > n)
				j = 1;
		}
		if (a[i][j] == 0)
			a[i][j] = k;
		else
		{
			i+=2;
			j--;
			a[i][j] = k;
		}
	}

	//���ħ����
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}
