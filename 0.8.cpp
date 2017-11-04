# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int x; //全局变量

int main(void)
{
	extern int x; //可选的二次声明
	char number[30];

	//置随机数
 	int i;

	putc(getc(stdin),stderr);//标准文件指针标准输入-stdin-键盘，标准输出-stdout-显示器，标准错误-stderr-显示器
	
// 	scanf("%d", &x); //置随机数种子
// 	srand(x);
// 	for (i=0; i<5; i++)
//		printf("%d\n", rand());
	//自动重置种子
// 	srand((unsigned int)time(0));
// 	for (i=0; i<5; i++)
// 		printf("%d\n", rand());


	//strlen
// 	int ct = -1;
// 	scanf("%s", number);
// 	while(*(number+(++ct))!='\0');
// 	printf("strlen(number) = %d\n", ct);
// 	printf("number = %d\n", atoi(number)); //把字符串中的数字转换为int类型
// 	printf("number = %lf\n", atof(number)); //把字符串中的数字转换为double类型

	
// 	while (gets_s(number) && number[0]!='\0')
// 	//检测数组第一个char是否为‘\0’是为了防止无输入时还执行循环体的命令
// 	{
// 		printf("jj\n");
// 	}
	system("pause");
	return 0;
}