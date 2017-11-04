/*
	2016年12月18日16:01:42
*/

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define SQS_INIT_SIZE 100
# define SQSINCREMENT 10
# define BUFFERSIZE 10

typedef double ElemType;
typedef struct SqStack
{
	ElemType * pBottom;
	ElemType * pTop;
	int StackSize;
} SQSTACK, * PSQSTACK;

void InitSQS(PSQSTACK s);
void Push(PSQSTACK s, ElemType val);
int SQSLen(SQSTACK s);
void Pop(PSQSTACK s, ElemType * pVal);
double CreateDigit(char * digit);



int main(void)
{
	SQSTACK s;
	char c;
	double d, e;
	char digit[BUFFERSIZE];
	int i = 0;

	InitSQS(&s);

	printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开：\n");
	c = getchar();
	while (c != '\n')
	{
		while (isdigit(c) || c=='.')
		{
			digit[i++] = c;
			digit[i] = '\0';
			if (i>=BUFFERSIZE)
			{
				printf("ERROR,输入的单个数值的长度过大！\n");
				return -1;
			}
			c = getchar();
			if (c == ' ')
			{
				e = CreateDigit(digit);
				Push(&s, e);
				i = 0;
				break;
			}
		}
		switch(c)
		{
		case '+':	
			Pop(&s, &d);
			Pop(&s, &e);
			Push(&s, e+d);
			break;
		case '-':
			Pop(&s, &d);
			Pop(&s, &e);
			Push(&s, e-d);
			break;
		case '*':	
			Pop(&s, &e);
			Pop(&s, &d);
			Push(&s, d*e);
			break;
		case '/':	
			Pop(&s, &e);
			Pop(&s, &d);
			Push(&s, d/e);
			break;
		}
		

		c = getchar();
	}

	Pop(&s, &e);
	printf("最终的计算结果为：%f\n", e);

	system("pause");
	return 0;
}

void InitSQS(PSQSTACK s)
{
	s->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == s->pBottom)
	{
		printf("栈分配空间失败！\n");
		system("pause");
		exit(0);
	}
	s->pTop = s->pBottom;
	s->StackSize = SQS_INIT_SIZE;
}

void Push(PSQSTACK s, ElemType val)
{
	if ((s->pTop)-(s->pBottom) >= s->StackSize)
	{
		s->pBottom = (ElemType *)realloc(s->pBottom, sizeof(ElemType)*(s->StackSize+SQSINCREMENT));
		if (NULL == s->pBottom)
		{
			printf("栈分配空间失败！\n");
			system("pause");
			exit(0);
		}
		s->pTop = s->pBottom + s->StackSize;
		s->StackSize += SQSINCREMENT;
	}
	*(s->pTop++) = val;
}

int SQSLen(SQSTACK s)
{
	return ( s.pTop - s.pBottom );
}

void Pop(PSQSTACK s, ElemType * pVal)
{
	if (s->pTop == s->pBottom)
		return ;
	*pVal = *(--(s->pTop));
}

double CreateDigit(char * digit)
{
	return atof(digit);
}

/*
	测试：
	(1)	8 + (8 + 8) * 8 + 8 / 4 可以转化成：
		8 8 8 + 8 * + 8 4 / +
		输出为：：138.000000

  (1)	5 - (6 + 7) * 2 + 4 / 2 可以转化成：
		5 6 7 + 2 * - 4 2 / +
		输出为：-19.000000
*/