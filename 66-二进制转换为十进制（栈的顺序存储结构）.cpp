/*
	2016年12月18日10:39:33
	2016年12月18日11:22:13
	时长：42分钟40秒
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define SQS_INIT_SIZE 20
# define SQSINCREMENT 10

/*
	'0'==48, '1'==49
*/

typedef char ElemType;
typedef struct SqStack
{
	ElemType * pBottom;
	ElemType * pTop;
	int StackSize;
} SQSTACK, * PSQSTACK;

PSQSTACK InitSqStack(void);
void Push(PSQSTACK s, ElemType val);
int Pop_n_Count(PSQSTACK s);
void DestroySqStack(PSQSTACK s);

int main(void)
{
	PSQSTACK s;
	ElemType t;

	s = InitSqStack();

	printf("请输入一个二进制数：");
	t = getchar();
	while (t != '\n')
	{
		Push(s, t);
		t = getchar();
	}
	printf("该二进制数的十进制形式是：%d\n", Pop_n_Count(s));

	DestroySqStack(s);
	
	system("pause");
	return 0;
}

PSQSTACK InitSqStack(void)
{
	PSQSTACK s = (PSQSTACK)malloc(sizeof(SQSTACK));
	if (NULL == s)
	{
		printf("栈创建失败！\n");
		system("pause");
		exit(0);
	}
	s->pBottom = (ElemType *)malloc(SQS_INIT_SIZE*sizeof(ElemType));
	if (NULL == s->pBottom)
	{
		printf("栈创建失败！\n");
		system("pause");
		exit(0);
	}
	s->pTop = s->pBottom;
	s->StackSize = SQS_INIT_SIZE;

	return s;
}

void Push(PSQSTACK s, ElemType val)
{
	if ((s->pTop)-(s->pBottom) >= s->StackSize)
	{
		s->pBottom = (ElemType *)realloc(s->pBottom,(s->StackSize+SQSINCREMENT)*sizeof(ElemType));
		if (NULL == s->pBottom)
		{
			printf("栈扩容失败！\n");
			system("pause");
			exit(0);
		}
		s->pTop = s->pBottom + s->StackSize;
		s->StackSize += SQSINCREMENT;
	}
	if (val==48 || val==49)
	{
		*(s->pTop) = val;
		s->pTop++;
	}
	else
	{
		printf("输入的二进制数有误！\n");
		system("pause");
		exit(0);
	}
}

int Pop_n_Count(PSQSTACK s)
{
	int sum, i;

	sum = i = 0;
	while (s->pBottom != s->pTop)
	{
		sum += (*(--s->pTop)-48) * (int)pow(2, i++);
	}	

	return sum;
}

void DestroySqStack(PSQSTACK s)
{
	int i, len;

	free(s->pBottom);
	s->pTop = s->pBottom = NULL;
	
	free(s);
	s = NULL;
}
