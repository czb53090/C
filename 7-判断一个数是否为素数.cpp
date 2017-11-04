# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, num, isPrime=1;
	printf("请输入一个数字：");
	scanf("%d", &num);

	for (i=2; i<num; i++)
	{
		if (num%i == 0)
		{	
			isPrime = 0;
			break;
		}
	}
	
	if (isPrime == 1)
	{
		printf("是素数!\n");
	}
	else
	{
		printf("不是素数!\n");
	}
	system("pause");
	return 0;
}