# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[100] = {0};
	int x, y, i, n=0;

	while (n < 2)
	{
		scanf("%d %d", &x, &y);
		a[x] += y;
		if (x == 0)
			n++;
	}


	n=0;
	for (i=99; i>=0; i--)
	{
		if (a[i] != 0)
		{
			if (i > 1)
			{				
				if (n == 0)
				{
					printf("%d", a[i]);
					printf("x");
					printf("%d", i);
					n++;
					continue;
				}
				printf("+");
				printf("%d", a[i]);
				printf("x");
				printf("%d", i);
			}
			else 
			{
				printf("+");
				printf("%d", a[i]);
				if(i == 1)
					printf("x");
			}
		}
	}

	system("pause");
	return 0;
}