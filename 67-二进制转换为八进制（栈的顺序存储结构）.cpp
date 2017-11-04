/*
	思路：  创建两个栈，一个放二进制数，一个存放八进制数
			每3位二进制数为一位8进制数，依次将计算的值放入八进制栈中
	2016年12月18日14:03:18 
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define SQS_INIT_SIZE 20
# define SQSINCREMENT 10

typedef char ElemType;

typedef struct SqStack
{
	ElemType * pBottom;
	ElemType * pTop;
	int StackSize;
} SQS, * PSQS;

void Init(PSQS s);
void Push(PSQS s, int val);
int SQSLen(SQS s);
void Pop(PSQS s, ElemType * pVal);
void Count(PSQS s1, PSQS s2);
void TraverseSQS(PSQS s);

int main(void)
{
	SQS B, O;
	ElemType val;

	Init(&B);
	Init(&O);

	printf("请输入要转化为八进制数的二进制数：");
	val = getchar();
	while (val != '\n')
	{
		Push(&B, val);
		val = getchar();
	}

	Count(&B, &O);
	printf("结果是：");
	TraverseSQS(&O);

	system("pause");
	return 0;

}

void Init(PSQS s)
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

void Push(PSQS s, int val)
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

int SQSLen(SQS s)
{
	return (s.pTop-s.pBottom);
}

void Pop(PSQS s, ElemType * pVal)
{
	*pVal = *(--(s->pTop));
}

void Count(PSQS s1, PSQS s2)
{
	int i, j, len, sum;
	ElemType val;

	len = SQSLen(*s1);

	for (j=1, i=sum=0; i<len; i++,j++)
	{
		Pop(s1, &val);
		sum += (val-48) * (int)pow(2, j-1);
		if (j%3 == 0)			
		{
			Push(s2, sum);
			sum = 0;
			j = 0;
		}
	}
}

void TraverseSQS(PSQS s)
{
	ElemType * r = s->pTop;
	while (r != s->pBottom)
		printf("%d", *(--r));
	printf("\n");
}
