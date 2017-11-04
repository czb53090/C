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
void Pop(PSQS pS, ElemType * pVal);

int main(void)
{
	SQS S;
	char c, e, sum;
	int i=0, j;

	Init_SQS(&S);

	printf("�������������");
	c = getchar();
	while (c != '\n')
	{
		i++;
		Push(&S, c);
		if (i%4 == 0)
		{
			if (i == 4)
				printf("ʮ��������ʽ�ǣ�");
			for (j=0,sum=0; j<4; j++)
			{
				Pop(&S, &e);
				sum += (e-48)*(char)pow(2, j);
			}
			printf("%01X", sum);
		}

		c = getchar();
	}


	printf("\n");

	system("pause");
	return 0;
}

void Init_SQS(PSQS pS)
{
	pS->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == pS->pBottom)
	{
		printf("Ϊջ����ռ�ʧ�ܣ�\n");
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
			printf("Ϊջ����ռ�ʧ�ܣ�\n");
			system("pause");
			exit(0);
		}
		pS->pTop = pS->pBottom + SQSINCREMENT;
		pS->StackSize += SQSINCREMENT;
	}
	*(pS->pTop++) = val;
}

void Pop(PSQS pS, ElemType * pVal)
{
	if (pS->pTop == pS->pBottom)
		return;
	*pVal = *(--pS->pTop);
}
