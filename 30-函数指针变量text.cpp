# include <stdio.h>
# include <stdlib.h>

void fun(int x, int y, int (*p)(int, int));
int max(int x, int y);
int min(int x, int y);
int add(int x, int y);

int main(void)
{
	int n=0, a=3, b=5;
	printf("a = %d, b = %d\nplease input number(1-man, 2-min, 3-add):\n", a, b);
	scanf("%d", &n);

	if (n == 1)
		fun(a, b, max);
	else if (n == 2)
		fun(a, b, min);
	else if (n == 3)
		fun(a, b, add);

	system("pause");
	return 0;
}

void fun(int x, int y, int (*p)(int, int))
{
	int result;
	result = (*p)(x,y);
	printf("%d", result);
}

int max(int x, int y)
{
	printf("The max is:");
	return (x>y?x:y);
}

int min(int x, int y)
{
	printf("The min is:");
	return (x<y?x:y);
}

int add(int x, int y)
{
	printf("The add is:");
	return (x+y);
}