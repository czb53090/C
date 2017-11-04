/*
	目的：
		设计在M*N（元素个数为偶数）的矩阵中，随机生成成对分布的大写字母
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define M 9
# define N 8

void Looma(char str[][N]);

int main(void)
{
	int i, j, k;
	char str[M][N] = {0};
	
	Looma(str);

	for(k=0; k<=N*3; k++)
	{
		if (k == 0)
		{
			printf("┏");
			continue;
		}
		if (k == N*3)
		{
			printf("┓");
			continue;
		}
		if (k%3 == 0)
		{
			printf("┳");
			continue;
		}
		printf("━");
	
	}
	printf("\n");
	for (i=0; i<M; i++)
	{
		for (j=0; j<N; j++)
		{

			if(j == N-1)
			{
				printf("┃ %c  ┃", str[i][j]);
				continue;
			}
			printf("┃ %c  ", str[i][j]);
			
		}
		printf("\n");
		if (i<M-1)
		{
			for(k=0; k<N*3; k++)
			{
				if(k == 0)
				{
					printf("┣");
					continue;
				}
				if(k%3 == 0 && k!=0)
				{
					printf("╋");
					continue;
				}
					printf("━");
			}
		}
		else
		{
			for(k=0; k<=N*3; k++)
			{
				if (k == 0)
				{
					printf("┗");
					continue;
				}
				if (k == N*3)
				{	
					printf("┛");
					continue;
				}
				if (k%3 == 0)
				{
					printf("┻");
					continue;
				}
				printf("━");	
			}
			printf("\n");
			continue;
		}
		printf("┫\n");
	}

	system("pause");
	return 0;
}

void Looma(char str[][N])
{
	int i1=0, j1=1, i2=2, j2=3, n;
	srand((unsigned)time(NULL));
	
	for (n=M*N/2; n--; )
	{
		while(str[i1][j1] != 0)
		{
			i1 = rand() % M;
			j1 = rand() % N; 
		}
		
		str[i1][j1] = 65 + rand()%26;
		
		while (str[i2][j2] != 0)
		{
			i2 = rand() % M;
			j2 = rand() % N; 
		}
		str[i2][j2] = str[i1][j1];
	}
}