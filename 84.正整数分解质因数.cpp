// c���Ա�д
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int num, int * a);
void g(int k);

int main(void)
{
	int n; // n������Ŵ���1������
	char c = 'y';

	while(c=='y' || c=='Y')
	{
		printf("������һ������1��������");
		scanf("%d", &n);
		if (n>1 && n<=INT_MAX)
		{
			printf("%d = ", n);
			g(n);
			printf("\b \n\n");
		}
		else
		{
			printf("��������\n");
			while (getchar() != '\n')
				;
			continue;
		}
		printf("�Ƿ����(y/n)��");
		while (getchar() != '\n')
			;
		scanf("%c", &c);
	}

	system("pause");
	return 0;
}

int f(int num, int * a)
{
	int flag = 1;

	for (int i=2; i<num; i++)
		if (num%i == 0)
		{
			*a = i;
			flag = 0;
			break;
		}

	return flag;
}

void g(int n)
{
	int k, flag; // flag���ж�n�Ƿ�Ϊ������k�����С������

	flag = f(n, &k);

	if (flag)
		printf("%d*", n);
	else
	{
		printf("%d*", k);
		g(n/k);
	}
}
