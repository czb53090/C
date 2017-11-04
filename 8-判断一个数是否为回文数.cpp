# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int x, i, sum=0, t;
	printf("请输入一个数字：");
	scanf("%d", &x);
	
	t = x;
	while (t > 0)
	{
		sum = sum*10 + t%10;
		t /= 10;
	}

	if (sum == x)
		printf("是回文数\n");
	else
		printf("不是回文数\n");



	system("pause");
	return 0;
}