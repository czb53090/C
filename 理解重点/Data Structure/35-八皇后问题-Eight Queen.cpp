# include <stdio.h>
# include <stdlib.h>

int count = 0; //不进行初始化也可以，因为全局变量会自动初始化为0

void EightQueen(int row, int n, int (*chess)[8]);
int NotDanger(int row, int j, int (*chess)[8]);

int main(void)
{
	int chess[8][8] = {0};

	EightQueen(0, 8, chess);//第0行开始，总共有8列

	system("pause");
	return 0;
}


//row			表示起始行
//n				表示列数
//(*chess)[8]	表示棋盘每一行的指针
void EightQueen(int row, int n, int (*chess)[8])
{
	int chess2[8][8], i, j;

	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
			chess2[i][j] = *(*(chess+i)+j);

	if (8 == row)
	{
		printf("第 %d 种：\n", count+1);
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				printf("%d ", *(*(chess+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{
		for (j=0; j<n; j++)
		{
			if (NotDanger(row, j, chess)) //判断是否危险
			{
				for (i=0; i<8; i++)
				{
					*(*(chess2+row)+i) = 0;
				}
				*(*(chess2+row)+j) = 1; 

				EightQueen(row+1, n, chess2);
			}
		}
	}
}

int NotDanger(int row, int j, int (*chess)[8])
{
	int i, k, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0;

	//判断列方向
	for (i=0; i<8; i++)
	{
		if (*(*(chess+i)+j) != 0)
		{
			flag1 = 1;
			break;
		}
	}
	//判断左上方
	for (i=row,k=j; i>=0 && k>=0; i--,k--)
	{
		if (*(*(chess+i)+k) != 0)
		{
			flag2 = 1;
			break;
		}
	}
	//判断右下方
	for (i=row,k=j; i<8 && k<8; i++,k++)
	{
		if (*(*(chess+i)+k) != 0)
		{
			flag3 = 1;
			break;
		}
	}
	//判断右上方
	for (i=row,k=j; i>=0 && k<8; i--,k++)
	{
		if (*(*(chess+i)+k) != 0)
		{
			flag4 = 1;
			break;
		}
	}
	//判断左下方
	for (i=row,k=j; i<8 && k>=0; i++,k--)
	{
		if (*(*(chess+i)+k) != 0)
		{
			flag5 = 1;
			break;
		}
	}

	if (flag1 || flag2 || flag3 || flag4 ||flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}