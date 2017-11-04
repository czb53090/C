# include <stdio.h>
# include <stdlib.h>
# define MAXSIZE 100
# define STACKINCREMENT 10

typedef int DATATYPE;
typedef struct Stack
{
	DATATYPE * pBottom;
	DATATYPE * pTop;
	int StackSize;
} SQSTACK;

SQSTACK * InitSQstack(void);
void SQstackPush(SQSTACK * s, DATATYPE val);
void SQstackPop(SQSTACK * s, DATATYPE * pVal);
void TraverseSQS(SQSTACK * s);

int main(void)
{
	DATATYPE val;

	SQSTACK * pSQS;
	int i = 120;

	pSQS = InitSQstack();

	while(--i)
		SQstackPush(pSQS, 120-i);
	TraverseSQS(pSQS);

	SQstackPop(pSQS, &val);
	printf("出栈的元素是：%d\n", val);
	TraverseSQS(pSQS);

	system("pause");
	return 0;
}

SQSTACK * InitSQstack(void)
{
	SQSTACK * s = (SQSTACK *)malloc(sizeof(SQSTACK));
	s->pBottom = (DATATYPE *)malloc(sizeof(DATATYPE)*MAXSIZE);
	if (NULL==s->pBottom && NULL==s)
	{
		printf("队列创建失败!\n");
		system("pause");
		exit(0);
		}
	s->StackSize = MAXSIZE;
	s->pTop = s->pBottom;

	return s;
}

void SQstackPush(SQSTACK * s, DATATYPE val)
{
	if ((s->pTop)-(s->pBottom) >= s->StackSize)
	{
		s->pBottom = (DATATYPE *)realloc(s->pBottom, (s->StackSize+STACKINCREMENT)*sizeof(DATATYPE));
		if (NULL == s->pBottom)
		{
			printf("队列扩容失败!\n");
			system("pause");
			exit(0);
		}
		s->pTop = s->pBottom + s->StackSize;
		s->StackSize += STACKINCREMENT; 
	}
	*(s->pTop) = val;
	s->pTop++;
}

void SQstackPop(SQSTACK * s, DATATYPE * pVal)
{
	if (s->pTop == s->pBottom)
		return ;
	*pVal = *(--(s->pTop));
}

void TraverseSQS(SQSTACK * s)
{
	DATATYPE val, count=0;
	while (s->pTop != s->pBottom)
	{
		count++;
		val = *--(s->pTop);
		printf("%d ", val);
		if (count%10 == 0)
			printf("\n");
	}
	s->pTop += count;
	printf("\n");
}