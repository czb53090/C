/*
	思路：
		n=3时执行 hanoi(2,A,C,B）。当执行它时，它会调用函数
		void hanoi(int n,char A,char B,char C)；也就是自己调用
		自己本身，而n==2(n!=1)执行注意这里是 hanoi(1,A,B,C);
		move(A,B); hanoi(1,C,A,B)；继续执行，继续调用本身，
		此时n=1，则执行注意这里是 move(A,C); move(A,B);move(C,B);
		上面所述才只执行了hanoi(2,A,C,B);后面还有move(A,C); 
		hanoi(2,B,A,C)；执行move(A,C);后再继续执行 hanoi(2,B,A,C)；
		照上述分析，n=2时调用自己，执行hanoi(1,B,C,A);move(B,C);
		hanoi(1,A,B,C);此时n=1,执行move(B,A); move(B,C); move(A,C); 
*/
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	void hanoi(int n, char one, char two, char three); //hanoi函数声明
	int m;
	printf("input the number of diskes:");
	scanf("%d", &m);

	printf("The step to move %d diskes:\n", m);
	hanoi(m, 'A', 'B', 'C');

	system("pause");
	return 0;
}

void hanoi(int n, char one, char two, char three) //定义hanoi函数
	//将n个盘从one座借助two座，移到three座
{
	void move(char x, char y); //对move函数的声明
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