/*
题目内容：
UTC是世界协调时，BJT是北京时间，UTC时间相当于BJT减去8。现在，你的程序要读入一个整数，表示BJT的时和分。
整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；
如果分小于10分，需要保留十位上的0。如1124表示11点24分，而905表示9点5分，36表示0点36分，7表示0点7分。
有效的输入范围是0到2359，即你的程序不可能从测试服务器读到0到2359以外的输入数据。
你的程序要输出这个时间对应的UTC时间，输出的格式和输入的相同，即输出一个整数，表示UTC的时和分。整数的个位
和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果小时是0，则没有百位部分；如果分小于
10分，需要保留十位上的0。
提醒：要小心跨日的换算。

输入格式:
一个整数，表示BJT的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果
小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。

输出格式：
一个整数，表示UTC的时和分。整数的个位和十位表示分，百位和千位表示小时。如果小时小于10，则没有千位部分；如果
小时是0，则没有百位部分；如果分小于10分，需要保留十位上的0。

输入样例：
903

输出样例：
103*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int num;

	scanf("%d", &num);

	if (num>=0 && num<=2359)
	{
		int M, H;

		M = num%100;
		H = num/100;

		if (H < 8)
		{
			H += 4;
			printf("%d%02d\n", H, M);
		}
		else if (H == 8)
			printf("%02d\n", M);
		else
			printf("%d%02d\n", H-8, M);
	}

	system("pause");
	return 0;
}