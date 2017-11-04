// c语言编写
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int num, int * a);
void g(int k);

int main(void)
{
	int n; // n用来存放大于1的整数
	char c = 'y';

	while(c=='y' || c=='Y')
	{
		printf("请输入一个大于1的整数：");
		scanf("%d", &n);
		if (n>1 && n<=INT_MAX)
		{
			printf("%d = ", n);
			g(n);
			printf("\b \n\n");
		}
		else
		{
			printf("输入有误\n");
			while (getchar() != '\n')
				;
			continue;
		}
		printf("是否继续(y/n)？");
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
	int k, flag; // flag来判断n是否为素数，k存放最小的因数

	flag = f(n, &k);

	if (flag)
		printf("%d*", n);
	else
	{
		printf("%d*", k);
		g(n/k);
	}
}
