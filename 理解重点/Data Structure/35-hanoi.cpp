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

//�� n �����Ӵ� x ���� y �ƶ��� z ��
void move(int n, char x, char y, char z)
{
	if (n == 1)
		printf("%c-->%c\n", x, z);
	else
	{
		move(n-1, x, z, y);			//�� n-1 �����Ӵ� x ���� z �ƶ��� y ��
		printf("%c-->%c\n", x, z);	//���� n ������ֱ�Ӵ� x �ƶ��� z ��
		move(n-1, y, x, z);			//�� n-1 �����Ӵ� y ���� x �ƶ��� z ��
	}

}