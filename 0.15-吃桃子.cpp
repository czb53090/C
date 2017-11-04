#include <stdio.h>
#include <stdlib.h>

int f(int n);

int main(void)
{
	int n = f(7);
	printf("%d", n);

	system("pause");
	return 0;
}


int f(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return 2*(f(n-1)+1);
	}
}