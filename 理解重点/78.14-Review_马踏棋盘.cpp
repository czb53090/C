# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define MAXSIZE 8

int chess[MAXSIZE][MAXSIZE];

int NextStep(int * x, int * y, int count);
int TraverseChessBoard(int x, int y, int falg);
void Input();

int main(void)
{
	clock_t start, finish;
	int i, j;

	start = clock();

	for (i=0; i<MAXSIZE; i++)
		for (j=0; j<MAXSIZE; j++)
			chess[i][j] = 0;

	TraverseChessBoard(2, 0, 1);

	finish = clock();

	printf("\n本次计算共耗时：%f\n", (double)(finish-start)/CLOCKS_PER_SEC);

	system("pause");
	return 0;
}

int NextStep(int * x, int * y, int count)
{
	switch (count)
	{
	case 0:
		if (*x+1<MAXSIZE && *y-2>=0 && 0==chess[*x+1][*y-2])
		{
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	case 1:
		if (*x+1<MAXSIZE && *y+2<MAXSIZE && 0==chess[*x+1][*y+2])
		{
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	case 2:
		if (*x+2<MAXSIZE && *y-1>=0 && 0==chess[*x+2][*y-1])
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 3:
		if (*x+2<MAXSIZE && *y+1<MAXSIZE && 0==chess[*x+2][*y+1])
		{
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 4:
		if (*x-1>=0 && *y-2>=0 && 0==chess[*x-1][*y-2])
		{
			*x -= 1;
			*y -= 2;
			return 1;
		}
		break;
	case 5:
		if (*x-1>=0 && *y+2<MAXSIZE && 0==chess[*x-1][*y+2])
		{
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	case 6:
		if (*x-2>=0 && *y-1>=0 && 0==chess[*x-2][*y-1])
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 7:
		if (*x-2>=0 && *y+1<MAXSIZE && 0==chess[*x-2][*y+1])
		{
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	}
	return 0;
}

int TraverseChessBoard(int x, int y, int tag)
{
	int x0, y0, flag, count;

	x0 = x;
	y0 = y;
	flag = count = 0;
	
	chess[x][y] = tag;

	if (tag == MAXSIZE*MAXSIZE)
	{
		Input();
		return 1;
	}

	flag = NextStep(&x0, &y0, count);
	while (!flag && count<MAXSIZE-1)
	{
		count++;
		flag = NextStep(&x0, &y0, count);
	}

	while (flag)
	{
		if (TraverseChessBoard(x0, y0, tag+1))
			return 1;
		
		x0 = x;
		y0 = y;
		count++;
		flag = NextStep(&x0, &y0, count);
		while (!flag && count<MAXSIZE-1)
		{
			count++;
			flag = NextStep(&x0, &y0, count);
		}
	}

	if (!flag)
		chess[x][y] = 0;
	
	return 0;
}

void Input()
{
	int i, j;

	for (i=0; i<MAXSIZE; i++)
	{
		for (j=0; j<MAXSIZE; j++)
			printf("%-3d", chess[i][j]);
		printf("\n");
	}
}