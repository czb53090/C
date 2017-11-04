/*
	˼·��
		n=3ʱִ�� hanoi(2,A,C,B������ִ����ʱ��������ú���
		void hanoi(int n,char A,char B,char C)��Ҳ�����Լ�����
		�Լ�������n==2(n!=1)ִ��ע�������� hanoi(1,A,B,C);
		move(A,B); hanoi(1,C,A,B)������ִ�У��������ñ���
		��ʱn=1����ִ��ע�������� move(A,C); move(A,B);move(C,B);
		����������ִֻ����hanoi(2,A,C,B);���滹��move(A,C); 
		hanoi(2,B,A,C)��ִ��move(A,C);���ټ���ִ�� hanoi(2,B,A,C)��
		������������n=2ʱ�����Լ���ִ��hanoi(1,B,C,A);move(B,C);
		hanoi(1,A,B,C);��ʱn=1,ִ��move(B,A); move(B,C); move(A,C); 
*/
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	void hanoi(int n, char one, char two, char three); //hanoi��������
	int m;
	printf("input the number of diskes:");
	scanf("%d", &m);

	printf("The step to move %d diskes:\n", m);
	hanoi(m, 'A', 'B', 'C');

	system("pause");
	return 0;
}

void hanoi(int n, char one, char two, char three) //����hanoi����
	//��n���̴�one������two�����Ƶ�three��
{
	void move(char x, char y); //��move����������
	if (n == 1)
		move(one, three);
	else
	{
		hanoi(n-1, one, three, two);
		move(one, three);
		hanoi(n-1, two, one, three);
	}
}

void move(char x, char y)
{
	printf("%c->%c\n", x, y);
}