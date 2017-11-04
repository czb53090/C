# include <stdio.h>
# include <stdlib.h>

void move(int n, char a, char b, char c);

int main(void)
{
	char a='A', b='B', c='C';
	int n;

	printf("input number of plies for hanoi:");
	scanf("%d", &n);
	printf("Now steps are as follows:\n");

	move(n, a, b, c);

	system("pause");
	return 0;
}

//将 n 个盘子从 x 借助 y 移动到 z 上
void move(int n, char x, char y, char z)
{
	if (n == 1)
		printf("%c-->%c\n", x, z);
	else
	{
		move(n-1, x, z, y);			//将 n-1 个盘子从 x 借助 z 移动到 y 上
		printf("%c-->%c\n", x, z);	//将第 n 个盘子直接从 x 移动到 z 上
		move(n-1, y, x, z);			//将 n-1 个盘子从 y 借助 x 移动到 z 上
	}

}