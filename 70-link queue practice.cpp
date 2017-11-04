# include <stdio.h>
# include <stdlib.h>

/*
	2016��12��19��15:50:43
	Ŀ�ģ�  ��дһ����ʽ���У���������һ���ַ����ԣ�#��������'\n',Ҳһ����
			��Ϊ������־��Ȼ�󽫶����е�Ԫ����ʾ����Ļ�ϡ�
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

	printf("��������һ���ַ���");
	c = getchar();
	while (c != '\n')
	{
		En_Queue(&Q, c);
		c = getchar();
	}

	printf("�����������ǣ�\n");
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
		printf("���г�ʼ��ʧ�ܣ�\n");
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
		printf("���г�ʼ��ʧ�ܣ�\n");
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