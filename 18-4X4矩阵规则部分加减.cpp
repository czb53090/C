# include <stdio.h>
# include <stdlib.h>
# define N 4

int main(void)
{
	int a[N][N];
	int i, j;

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			scanf("%d", &a[i][j]);
	printf("\n");

	for (i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
			a[i][j]+=2;
		for(j=0; j<i; j++)
			a[i][j]-=2;
	}
	
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;
}