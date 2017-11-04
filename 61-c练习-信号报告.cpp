/*
��Ŀ���ݣ�
���ߵ�̨��RS���źű�������������������ɵģ�
R(Readability) �źſɱ�ȼ�������.
S(Strength)    �ź�ǿ�ȼ���С.
����Rλ�ڱ����һλ������5������1��5���ֱ�ʾ.
1---Unreadable
2---Barely readable, occasional words distinguishable
3---Readable with considerable difficulty
4---Readable with practically no difficulty
5---Perfectly readable
����ڶ�λ��S�����־Ÿ�������1��9�е�һλ���ֱ�ʾ
1---Faint signals, barely perceptible
2---Very weak signals
3---Weak signals
4---Fair signals
5---Fairly good signals
6---Good signals
7---Moderately strong signals
8---Strong signals
9---Extremely strong signals
���ڣ���ĳ���Ҫ����һ���źű�������֣�Ȼ�������Ӧ�ĺ��塣�����59���������
Extremely strong signals, perfectly readable.
�����ʽ:
һ���������źű��档������ʮλ���ֱ�ʾ�ɱ�ȣ���λ���ֱ�ʾǿ�ȡ������������Χ��[11,59]��\
�����Χ������ֲ����ܳ����ڲ��������С�

�����ʽ��
һ�仰����ʾ����źű�������塣������Ŀ�е����֣��������ʾǿ�ȵ����֣����϶��źͿո�
Ȼ���Ǳ�ʾ�ɱ�ȵ����֣����Ͼ�š�ע��ɱ�ȵľ��ӵĵ�һ����ĸ��Сд�ġ�ע������ı����Ŷ���Ӣ�ĵġ�
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
