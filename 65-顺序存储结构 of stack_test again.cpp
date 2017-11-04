# include <stdio.h>
# include <stdlib.h>
# define SQS_INIT_SIZE 100
# define SQSINCREMENT 10

typedef int ElemType;
typedef struct SqStack
{
	ElemType * pBottom;
	ElemType * pTop;
	int StackSize;
} SQSTACK, * PSQSTACK;

void Init_SQS(PSQSTACK pS);
int SQSLen(SQSTACK S);
void Push(PSQSTACK pS, ElemType val);
void Pop(PSQSTACK pS,  ElemType * pVal);
void Traverse_SQS(PSQSTACK pS);

int main(void)
{
	SQSTACK S;
	ElemType val;

	Init_SQS(&S);
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Push(&S, 4);
	Push(&S, 5);
	Push(&S, 6);
	printf("ջ�ĳ����ǣ�%d\n", SQSLen(S));
	Traverse_SQS(&S);

	Pop(&S, &val);
	printf("��ջ��Ԫ���ǣ�%d\n", val);
	Pop(&S, &val);
	printf("��ջ��Ԫ���ǣ�%d\n", val);
	Pop(&S, &val);
	printf("��ջ��Ԫ���ǣ�%d\n", val);
	Traverse_SQS(&S);


	system("pause");
	return 0;
}

void Init_SQS(PSQSTACK pS)
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

int SQSLen(SQSTACK S)
{
	return (S.pTop-S.pBottom);
}

void Push(PSQSTACK pS, ElemType val)
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
		pS->pTop = pS->pBottom + pS->StackSize;
		pS->StackSize += SQSINCREMENT;
	}
	*(pS->pTop++) = val;
}

void Pop(PSQSTACK pS,  ElemType * pVal)
{
	if (pS->pTop == pS->pBottom)
		return ;
	*pVal = *(--pS->pTop);
}

void Traverse_SQS(PSQSTACK pS)
{
	ElemType * p = pS->pTop;

	while ((p--) != pS->pBottom)
		printf("%d " , *p);
	printf("\n");
}