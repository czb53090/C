/*
	2016��11��20��19:29:11
	Ŀ�ģ���n��������ʹǰ�����˳�������m��λ�ã����m���������ǰ��m
		  ������
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

	a_end = a[n-1]; //�ȱ����������һ����

	for (p=a+n-1; p>a; p--) //ÿ��ѭ����һ��������
		*p = *(p-1);
	a[0] = a_end; //�Ƶ���һλ����ѭ���������һ������ֵ������һλ
				  //��������ʵ�����ƶ�һλ
	m--;
	if (m > 0) //�ݹ飬ֱ��m<0��ֱ�۵�Ҳ����Ҫ����move����m�Σ�ÿ���ƶ�һλ
		move(a, n, m);
}