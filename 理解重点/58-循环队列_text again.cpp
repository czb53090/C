/*
	2016��12��10��09:38:41
	2016��12��10��09:52:27
	�Բ�ʱ����13����46��
*/

# include <stdio.h>
# include <stdlib.h>
# define N 6

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
void Clear_queue(PQUEUE pQ);

int main(int argc, char const *argv[])
{
	QUEUE S;
	int val;

	Init_queue(&S);
	En_queue(&S, 1);
	En_queue(&S, 2);
	En_queue(&S, 3);
	En_queue(&S, 4);
	En_queue(&S, 5);
	if (!En_queue(&S, 6))
		printf("Ԫ��6����ʧ��!\n");
	Traverse_queue(&S);

	if (Out_queue(&S, &val))
		printf("���гɹ������е�Ԫ����%d.\n", val);
	else
		printf("����ʧ��!\n");
	if (Out_queue(&S, &val))
		printf("���гɹ������е�Ԫ����%d.\n", val);
	else
		printf("����ʧ��!\n");
	Traverse_queue(&S);
	if (Out_queue(&S, &val))
		printf("���гɹ������е�Ԫ����%d.\n", val);
	else
		printf("����ʧ��!\n");

	printf("��ն���!\n");
	Clear_queue(&S);
	Traverse_queue(&S);

	
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

	for (i=pQ->front; i!=pQ->rear; i++)
		printf("%d  ", pQ->pBase[i]);
	printf("\n");
}
void Clear_queue(PQUEUE pQ)
{
	if (Empty_queue(pQ))
		return;
	else
		pQ->rear = pQ->front;
}
