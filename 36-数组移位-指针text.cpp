/*
	2016年11月20日19:29:11
	目的：有n个整数，使前面各数顺序向后移m个位置，最后m个数变成最前面m
		  个数。
*/

# include <stdio.h>
# include <stdlib.h>

void move(int a[], int n, int m);

int main(void)
{
	int a[30];
	int n, m, i;

	printf("How many number: ");
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("How many place you want move: ");
	scanf("%d", &m);
	
	for (i=0; i<n; i++)
		printf("%-5d", a[i]);
	printf("\n");
	
	move(a, n, m);
	for (i=0; i<n; i++)
		printf("%-5d", a[i]);
	printf("\n");

	system("pause");
	return 0;
}

void move(int a[], int n, int m)
{
	int a_end;
	int * p;

	a_end = a[n-1]; //先保存数组最后一个数

	for (p=a+n-1; p>a; p--) //每轮循环将一个数后移
		*p = *(p-1);
	a[0] = a_end; //移到第一位跳出循环，将最后一个数的值赋给第一位
				  //这样就先实现了移动一位
	m--;
	if (m > 0) //递归，直到m<0，直观点也就是要调用move函数m次，每次移动一位
		move(a, n, m);
}