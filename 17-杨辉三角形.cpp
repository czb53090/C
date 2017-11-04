# include <stdio.h>
# include <stdlib.h>
# define N 15

int main(void)
{
	int i, j, k, a[N][N];

	for (i=0; i<N; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}

	for (i=2; i<N; i++)
		for (j=1; j<=i-1; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j];
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<=i; j++)
		{
			
			if (N <= 13)
			{
				if (j == 0)
				{
					for(k=0; k<N-i; k++)
					printf("  ");
				}
				printf("%-4d", a[i][j]);
				
				
			}
			else if (N <= 16)
			{	
				if (j == 0)
				{
					for(k=0; k<N-i; k++)
					printf("  ");
				}
				printf("%-5d", a[i][j]);
			}
			else
			{
				printf("%d ", a[i][j]);
			}
		}
		printf("\n");
		
	}

	system("pause");
	return 0;
}
