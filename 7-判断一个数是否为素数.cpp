# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, num, isPrime=1;
	printf("������һ�����֣�");
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
		printf("������!\n");
	}
	else
	{
		printf("��������!\n");
	}
	system("pause");
	return 0;
}