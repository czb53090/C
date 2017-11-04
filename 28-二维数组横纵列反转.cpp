# include <stdio.h>
# include <stdlib.h>
# define N 15

void convert(int a[][N], int len);

int main(void)
{
	int a[N][N], n, j, i;

	printf("input array n*n£ºn = ");
	scanf("%d", &n);
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	convert(a, n);	

	printf("convert array:\n");
	for (i=0; i<n; i++)
	{	for (j=0; j<n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}

void convert(int a[][N], int len)
{
	int i, j, t;
	for (i=0; i<len; i++)
		for (j=i+1; j<len; j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
}