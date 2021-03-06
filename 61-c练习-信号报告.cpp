/*
题目内容：
无线电台的RS制信号报告是由三两个部分组成的：
R(Readability) 信号可辨度即清晰度.
S(Strength)    信号强度即大小.
其中R位于报告第一位，共分5级，用1—5数字表示.
1---Unreadable
2---Barely readable, occasional words distinguishable
3---Readable with considerable difficulty
4---Readable with practically no difficulty
5---Perfectly readable
报告第二位是S，共分九个级别，用1—9中的一位数字表示
1---Faint signals, barely perceptible
2---Very weak signals
3---Weak signals
4---Fair signals
5---Fairly good signals
6---Good signals
7---Moderately strong signals
8---Strong signals
9---Extremely strong signals
现在，你的程序要读入一个信号报告的数字，然后输出对应的含义。如读到59，则输出：
Extremely strong signals, perfectly readable.
输入格式:
一个整数，信号报告。整数的十位部分表示可辨度，个位部分表示强度。输入的整数范围是[11,59]，\
这个范围外的数字不可能出现在测试数据中。

输出格式：
一句话，表示这个信号报告的意义。按照题目中的文字，先输出表示强度的文字，跟上逗号和空格，
然后是表示可辨度的文字，跟上句号。注意可辨度的句子的第一个字母是小写的。注意这里的标点符号都是英文的。
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int i, j;
	char a[5][50] = 
	{
		"unreadable",
		"barely readable, occasional words distinguishable",
		"beadable with considerable difficulty",
		"readable with practically no difficulty",
		"perfectly readable"
	};

	char b[9][50] = 
	{
		"Faint signals, barely perceptible",
		"Very weak signals",
		"Weak signals",
		"Fair signals",
		"Fairly good signals",
		"Good signals",
		"Moderately strong signals",
		"Strong signals",
		"Extremely strong signals",
	};

	scanf("%d", &i);
	j = i%10;
	i/=10;

	printf("%s,%s\n", b[j-1], a[i-1]);

	system("pause");
	return 0;
}
