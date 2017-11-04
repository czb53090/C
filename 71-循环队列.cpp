# include <stdio.h>
# include <stdlib.h>
# define MAXSIZE 10

typedef int ElemType;
typedef struct CNode
{
	ElemType * pBase;
	int front;
	int rear;
}CNODE, * PCNODE;

void InitCQueue(PCNODE pC);
bool Empty_CQueue(PCNODE pC);
bool Full_CQueue(PCNODE pC);
bool En_CQueue(PCNODE pC, ElemType val);
bool Out_CQueue(PCNODE pC, ElemType * pVal);
void Destroy_CQueue(PCNODE pC);
void Traverse_CQueue(PCNODE pC);

int main(void)
{
	CNODE C;
	ElemType val;

	InitCQueue(&C);

	En_CQueue(&C, 1);
	En_CQueue(&C, 2);
	En_CQueue(&C, 3);
	En_CQueue(&C, 4);
	En_CQueue(&C, 5);
	En_CQueue(&C, 6);
	Traverse_CQueue(&C);

	Out_CQueue(&C, &val);
	printf("出列的元素是：%d\n", val);

	Traverse_CQueue(&C);


	system("pause");
	return 0;
}

void InitCQueue(PCNODE pC)
{
	pC->pBase = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	if (NULL == pC->pBase)
	{
		printf("队列初始化失败！\n");
		system("pause");
		exit(0);
	}
	pC->front = pC->rear = 0;
}

bool Empty_CQueue(PCNODE pC)
{
	if (pC->front == pC->rear)
		return true;
	else
		return false;
}

bool Full_CQueue(PCNODE pC)
{
	if ((pC->rear+1)%MAXSIZE == pC->front)
		return true;
	else
		return false;
}

bool En_CQueue(PCNODE pC, ElemType val)
{
	if (Full_CQueue(pC))
		return false;
	else
	{
		pC->pBase[pC->rear] = val;
		pC->rear = (pC->rear+1) % MAXSIZE;

		return true;
	}
}

bool Out_CQueue(PCNODE pC, ElemType * pVal)
{
	if (Empty_CQueue(pC))
		return false;
	else
	{
		*pVal = pC->pBase[pC->front];
		pC->front = (pC->front+1) % MAXSIZE;

		return true;
	}
}
void Destroy_CQueue(PCNODE pC)
{
	free(pC->pBase);
}

void Traverse_CQueue(PCNODE pC)
{
	int i;

	for (i=pC->front; i!=pC->rear; i=(i+1)%MAXSIZE)
		printf("%d  ", pC->pBase[i]);
	printf("\n");
	return;
}
