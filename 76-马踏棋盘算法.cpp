# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define X 8
# define Y 8

int chess[X][Y];

int NextStep(int * x, int * y, int count);
int TraverseChessBoard(int x, int y, int tag);
void Input(void);

int main(void)
{
	clock_t start, finish;
	int i, j;

	start = clock();

	for (i=0; i<X; i++)
		for (j=0; j<Y; j++)
			chess[i][j] = 0;

	if (!TraverseChessBoard(2, 0, 1))
	{
		printf("马踏棋盘计算失败了！\n");
	}
	
	finish = clock();

	printf("\n本次计算一共耗时：%f\n", (double)(finish-start)/CLOCKS_PER_SEC);

	system("pause");
	return 0;
}

int NextStep(int * x, int * y, int count)
{
	switch ( count )
	{
	case 0:
		if (*x-2>=0 && *y+1<Y && 0==chess[*x-2][*y+1])
		{
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	case 1:
		if (*x+2<X && *y+1<Y && 0==chess[*x+2][*y+1])
		{
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 2:
		if (*x-1>=0 && *y+2<Y && 0==chess[*x-1][*y+2])
		{
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	case 3:
		if (*x+1<X && *y+2<Y && 0==chess[*x+1][*y+2])
		{
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	case 4:
		if (*x-2>=0 && *y-1>=0 && 0==chess[*x-2][*y-1])
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 5:
		if (*x+2<X && *y-1>=0 && 0==chess[*x+2][*y-1])
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 6:
		if (*x-1>=0 && *y-2>=0 && 0==chess[*x-1][*y-2])
		{
			*x -= 1;
			*y -= 2;
			return 1;
		}
		break;
	case 7:
		if (*x+1<X && *y-2>=0 && 0==chess[*x+1][*y-2])
		{
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	default:
		break;
	}

	return 0;
}

int TraverseChessBoard(int x, int y, int tag)
{
	int x1=x, y1=y, flag=0, count=0;
	chess[x][y] = tag;

	if (tag == X*Y)
	{
		Input();
		return 1;
	}

	flag = NextStep(&x1, &y1, count);
	while (flag==0 && count<7)
	{
		count++;
		flag = NextStep(&x1, &y1, count);
	}

	while ( flag )
	{
		if (TraverseChessBoard(x1, y1, tag+1))
			return 1;

		x1 = x;
		y1 = y;
		count++;
		flag = NextStep(&x1, &y1, count);
		while (flag==0 && count<7)
		{
			count++;
			flag = NextStep(&x1, &y1, count);
		}
	}

	if (0 == flag)
		chess[x][y] = 0;

	return 0;
}

void Input(void)
{
	int i, j;

	for (i=0; i<X; i++)
	{
		for (j=0; j<Y; j++)
		{
			printf("%2d\t", chess[i][j]);
		}
		printf("\n");
	}
}