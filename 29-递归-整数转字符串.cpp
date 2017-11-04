# include <stdio.h>
# include <stdlib.h>

void convert(int n);

int main(void)
{
	int number;
	printf("please input a number:");
	scanf("%d", &number);

	if (number < 0)
	{
		putchar('-');
		number = -number;
	}

	convert(number);

	system("pause");
	return 0;
}


void convert(int n)
{
	int i;
	if ((i=n/10)!=0)
		convert(i);
	putchar(n%10+'0');
	putchar(32);
}