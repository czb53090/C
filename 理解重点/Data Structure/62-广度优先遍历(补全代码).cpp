# include <stdio.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1
# define MAXSIZE 50
# define VexMaxNum 4

typedef char ElementType;

typedef struct Queue
{
	ElementType * pBase;
	int front;
	int rear;
} QUEUE, *PQUEUE;

typedef struct MGraph
{
	ElementType vex[VexMaxNum];
	int arc[VexMaxNum][VexMaxNum];
	int numVertexes;
} MGRAPH, * PMGRAPH;

void BFSTraverse(PMGRAPH G);
void InitQueue(PQUEUE * q);
int Q_IsEmpty(PQUEUE q);
int	Q_IsFull(PQUEUE q);
int EnQueue(PQUEUE q, ElementType val);
int DeQueue(PQUEUE q, ElementType * pVal);
void InitGraph(PMGRAPH * G);

int main(void)
{
	PMGRAPH G;
	int i, j;

	InitGraph(&G);

	
	for (i=0; i<VexMaxNum; i++)
		for (j=0; j<VexMaxNum; j++)
		{
			G->arc[i][j] = 1;
			if (i == j)
				G->arc[i][j] = 0;
		}

	G->arc[2][3] = 0;
	G->arc[3][2] = 0;
	
	G->numVertexes = VexMaxNum;
	for (i=0; i<VexMaxNum; i++)
		G->vex[i] = 'A' + i;
	
	BFSTraverse(G);

	system("pause");
	return 0;
}

//邻接矩阵的广度遍历算法
void BFSTraverse(PMGRAPH G)
{
	int i, j, visited[VexMaxNum];
	PQUEUE Q;
	ElementType val;

	for (i=0; i<G->numVertexes; i++)
	{
		visited[i] = FALSE;
	}

	InitQueue(&Q);
	
	for (i=0; i<G->numVertexes; i++)
	{
		if (!visited[i])
		{
			printf("EnQueue:%c ", G->vex[i]);
			visited[i] = TRUE;
			EnQueue(Q, G->vex[i]);

			while (!Q_IsEmpty(Q))
			{
				DeQueue(Q, &val);
				printf("OutQueue:%c\n", val);
				for (j=0; j<G->numVertexes; j++)
				{
					if (G->arc[i][j]==1 && !visited[j])
					{
						printf("%c ", G->vex[j]);
						visited[j] = TRUE;
						EnQueue(Q, G->vex[j]);
					}
				}
			}
			printf("\n");
		}
	}
}

void InitQueue(PQUEUE * q)
{
	*q = (PQUEUE)malloc(sizeof(QUEUE));
	(*q)->pBase = (ElementType *)malloc(sizeof(ElementType)*MAXSIZE);
	
	if (NULL==*q || NULL==(*q)->pBase)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}

	(*q)->front = (*q)->rear = 0;
}

int Q_IsEmpty(PQUEUE q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
	
}

int	Q_IsFull(PQUEUE q)
{
	if ((q->rear+1)%MAXSIZE == q->front)
		return 1;
	else
		return 0;
}

int EnQueue(PQUEUE q, ElementType val)
{
	if (Q_IsFull(q))
	{
		printf("Queue is full\n");
		system("pause");
		return 0;
	}
	else
	{
		q->pBase[q->rear] = val;
		q->rear = (q->rear+1) % MAXSIZE;
		return 1;
	}
}

int DeQueue(PQUEUE q, ElementType * pVal)
{
	if (Q_IsEmpty(q))
	{
		printf("Queue is empty!\n");
		system("pause");
		return 0;
	}
	else
	{
		*pVal = q->pBase[q->front];
		q->front = (q->front+1) % MAXSIZE;
		return 1;
	}
}

void InitGraph(PMGRAPH * G)
{
	*G = (PMGRAPH)malloc(sizeof(MGRAPH));
	
	if (NULL == *G)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}

	(*G)->numVertexes = 0;
}
