/*
	2016年12月9日15:10:46
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Queue
{
	PNODE front; //前部
	PNODE rear; //后部
}QUEUE, * PQUEUE;

void init(PQUEUE pQ);
bool Is_empty(PQUEUE pQ);
void in(PQUEUE pQ, int val);
void traverse(PQUEUE pQ);
bool out(PQUEUE pQ, int * pVal);
void clear(PQUEUE pQ);


int main(void)
{
	QUEUE Q;
	int val;

	init(&Q);
	in(&Q, 1);
	in(&Q, 2);
	in(&Q, 3);
	in(&Q, 4);
	in(&Q, 5);
	in(&Q, 6);
	in(&Q, 7);
	traverse(&Q);
	if(out(&Q, &val))
		printf("出列成功，出列的元素是：%d\n", val);
	else
		printf("出列失败!\n");
	if(out(&Q, &val))
		printf("出列成功，出列的元素是：%d\n", val);
	else
		printf("出列失败!\n");
	if(out(&Q, &val))
		printf("出列成功，出列的元素是：%d\n", val);
	else
		printf("出列失败!\n");
	traverse(&Q);

	printf("清空队列:\n");
	clear(&Q);
	traverse(&Q);
	if(out(&Q, &val))
		printf("出列成功，出列的元素是：%d\n", val);
	else
		printf("出列失败!\n");

	system("pause");
	return 0;
}

void init(PQUEUE pQ)
{
	pQ->front = pQ->rear = NULL;
}

bool Is_empty(PQUEUE pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

void in(PQUEUE pQ, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("分配内存失败!\n");
		system("pause");
		exit(0);
	}
	else
	{
		pNew->data = val;
		pNew->pNext = NULL;

		if (pQ->rear==NULL && pQ->front==NULL)
			pQ->front = pQ->rear = pNew;
		else
		{
			pQ->rear->pNext = pNew;
			pQ->rear = pNew;
		}
	}
	return;
}

void traverse(PQUEUE pQ)
{
	PNODE p = pQ->front;

	while(p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool out(PQUEUE pQ, int * pVal)
{
	PNODE p;
	if (Is_empty(pQ))
		return false;
	else
	{
		p = pQ->front;
		*pVal = p->data;
		pQ->front = p->pNext;
		free(p);
		p = NULL;
	}
	return true;
}

void clear(PQUEUE pQ)
{
	PNODE p1, p2;
	
	if (Is_empty(pQ))
		return;
	else
	{
		p1 = pQ->front;
		while(p1)
		{
			p2 = p1->pNext;
			free(p1);
			p1 = p2;
		}
		pQ->front = pQ->rear = NULL;
	}
	return;
}