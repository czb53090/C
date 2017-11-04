# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define SQS_INIT_SIZE 100
# define SQSINCREMENT 10

typedef char ElemType;
typedef struct SqStack
{
	ElemType * pTop;
	ElemType * pBottom;
	int StackSize;
}SQS, * PSQS;

void Init_SQS(PSQS pS);
void Push(PSQS pS, ElemType val);
void Pop(PSQS pS,  ElemType * pVal);
void Traverse_SQS(PSQS pS);

int main(void)
{
	char c, val, sum;
	SQS S1, S2;
	int j;

	Init_SQS(&S1);
	Init_SQS(&S2);

	printf("输入二进制数：");

	c = getchar();
	while (c != '\n')
	{
		Push(&S1, c);
		c = getchar();
	}

	sum = j = 0;
	do 
	{
		
		Pop(&S1, &val);
		sum += (val-48)*(char)pow(2, j++);
		if (j == 4)
		{
			j = 0;
			Push(&S2, sum);
			sum = 0;
		}
	} while (S1.pTop != S1.pBottom);

	printf("十六进制形式是：");
	Traverse_SQS(&S2);


	system("pause");
	return 0;
}

void Init_SQS(PSQS pS)
{
	pS->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == pS->pBottom)
	{
		printf("为栈分配空间失败！\n");
		system("pause");
		exit(0);
	}
	pS->pTop = pS->pBottom;
	pS->StackSize = SQS_INIT_SIZE;
}

void Push(PSQS pS, ElemType val)
{
	if (pS->pTop-pS->pBottom >= pS->StackSize)
	{
		pS->pBottom = (ElemType *)realloc(pS->pBottom, sizeof(ElemType)*(pS->StackSize+SQSINCREMENT));
		if (NULL == pS->pBottom)
		{
			printf("为栈分配空间失败！\n");
			system("pause");
			exit(0);
		}
		pS->pTop = pS->pBottom + pS->StackSize;
		pS->StackSize += SQSINCREMENT;
	}
	*(pS->pTop++) = val;
}

void Pop(PSQS pS,  ElemType * pVal)
{
	if (pS->pTop == pS->pBottom)
		return ;
	*pVal = *(--pS->pTop);
}

void Traverse_SQS(PSQS pS)
{
	ElemType * p = pS->pTop;

	while (p-- != pS->pBottom)
		printf("%X", *p);
	printf("\n");
}