/*
	2016��12��9��21:09:45
	2016��12��9��21:24:06
	��һ�����в��Խ����14����21��
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
		printf("Ԫ��6����ʧ��!\n");
	if(!En_queue(&Q, 7))
		printf("Ԫ��7����ʧ��!\n");
	Traverse_queue(&Q);

	if (Out_queue(&Q, &val))
		printf("���гɹ������е�Ԫ����%d��\n", val);
	else
		printf("����ʧ��!\n");
	if (Out_queue(&Q, &val))
		printf("���гɹ������е�Ԫ����%d��\n", val);
	else
		printf("����ʧ��!\n");
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