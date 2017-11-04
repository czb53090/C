# include <stdio.h>
# include <stdlib.h>

/*
	2016年12月19日15:50:43
	目的：  编写一个链式队列，任意输入一串字符，以（#，这里以'\n',也一样）
			作为结束标志，然后将队列中的元素显示到屏幕上。
*/

typedef char ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode * pNext;
}QNODE, * PQNODE;

typedef struct Queue
{
	PQNODE front;
	PQNODE rear;
}QUEUE, * PQUEUE;

void Init_Queue(PQUEUE pQ);
void En_Queue(PQUEUE pQ, ElemType val);
void Out_Queue(PQUEUE pQ, ElemType * pVal);
void Traverse_Queue(PQUEUE pQ);
void Destroy_Queue(PQUEUE pQ);

int main(void)
{
	ElemType c;
	QUEUE Q;

	Init_Queue(&Q);

	printf("任意输入一段字符：");
	c = getchar();
	while (c != '\n')
	{
		En_Queue(&Q, c);
		c = getchar();
	}

	printf("队列输出结果是：\n");
	Traverse_Queue(&Q);

	Destroy_Queue(&Q);

	system("pause");
	return 0;
}

void Init_Queue(PQUEUE pQ)
{
	pQ->front = pQ->rear = (PQNODE)malloc(sizeof(QNODE));
	if (NULL == pQ->rear)
	{
		printf("队列初始化失败！\n");
		system("pause");
		exit(0);
	}
	pQ->front->pNext = NULL;
}

void En_Queue(PQUEUE pQ, ElemType val)
{
	PQNODE pQNew =  (PQNODE)malloc(sizeof(QNODE));
	if (NULL == pQNew)
	{
		printf("队列初始化失败！\n");
		system("pause");
		exit(0);
	}
	pQNew->data = val;
	pQ->rear->pNext = pQNew;
	pQNew->pNext = NULL;
	pQ->rear = pQNew;
}

void Out_Queue(PQUEUE pQ, ElemType * pVal)
{
	PQNODE p;

	if (pQ->front == pQ->rear)
		return ;
	p = pQ->front->pNext;
	*pVal = p->data;
	pQ->front->pNext = p->pNext;
	if (p == pQ->rear)
		pQ->rear = pQ->front;
	free(p);
	p = NULL;
}

void Traverse_Queue(PQUEUE pQ)
{
	PQNODE p = pQ->front;

	while ((p=p->pNext) != NULL)
		printf("%c", p->data);
	printf("\n");
}

void Destroy_Queue(PQUEUE pQ)
{
	while(pQ->front)
	{
		pQ->rear = pQ->front->pNext;
		free(pQ->front);
		pQ->front = pQ->rear;	
	}
}