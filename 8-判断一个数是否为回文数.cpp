# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int x, i, sum=0, t;
	printf("������һ�����֣�");
	scanf("%d", &x);
	
	t = x;
	while (t > 0)
	{
		sum = sum*10 + t%10;
		t /= 10;
	}

	if (sum == x)
		printf("�ǻ�����\n");
	else
		printf("���ǻ�����\n");



	system("pause");
	return 0;
}