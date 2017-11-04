# include <stdio.h>
# include <stdlib.h>

void binary(int x);

int main(void)
{
	int x;
	printf("input the number you want swap:");
	scanf("%d", &x);
	binary(x);

	printf("\n");
	
	system("pause");
	return 0;
}

void binary(int x)
{
	int result=x;

	if(x > 0)
	{
		result = (x%2);
		binary(x/=2);
		printf("%d", result);
	}
	else
		result = 1;
}