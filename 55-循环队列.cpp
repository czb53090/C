/*
	2016年12月9日21:09:45
	2016年12月9日21:24:06
	第一次自行测试结果：14分钟21秒
*/
#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE, * PQUEUE;

void Init_queue(PQUEUE pQ);
bool Empty_queue(PQUEUE pQ);
bool Full_queue(PQUEUE pQ);
bool En_queue(PQUEUE pQ, int val);
bool Out_queue(PQUEUE pQ, int * pVal);
void Traverse_queue(PQUEUE pQ);

int main(void)
{
	QUEUE Q;
	int val;

	Init_queue(&Q);
	En_queue(&Q, 1);
	En_queue(&Q, 2);
	En_queue(&Q, 3);
	En_queue(&Q, 4);
	En_queue(&Q, 5);
	if(!En_queue(&Q, 6))
		printf("元素6入列失败!\n");
	if(!En_queue(&Q, 7))
		printf("元素7入列失败!\n");
	Traverse_queue(&Q);

	if (Out_queue(&Q, &val))
		printf("出列成功，出列的元素是%d。\n", val);
	else
		printf("出列失败!\n");
	if (Out_queue(&Q, &val))
		printf("出列成功，出列的元素是%d。\n", val);
	else
		printf("出列失败!\n");
	Traverse_queue(&Q);

	system("pause");
	return 0;
}

void Init_queue(PQUEUE pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int)*N);
	pQ->front = pQ->rear = 0;
	return;
}

bool Empty_queue(PQUEUE pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool Full_queue(PQUEUE pQ)
{
	if ((pQ->rear+1)%N == pQ->front)
		return true;
	else
		return false;
}

bool En_queue(PQUEUE pQ, int val)
{
	if (Full_queue(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1) % N;
		return true;
	}
}

bool Out_queue(PQUEUE pQ, int * pVal)
{
	if (Empty_queue(pQ))
		return false;
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1) % N;
		return true;
	}
}
void Traverse_queue(PQUEUE pQ)
{
	int i;

	for (i=pQ->front; i!=pQ->rear; i=(i+1)%N)
		printf("%d  ", pQ->pBase[i]);
	printf("\n");
	return;
}