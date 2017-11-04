# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 15

typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode * next;
} EDGENODE, * PEDGENODE;

typedef struct VertexNode
{
	int vex;
	int in;
	PEDGENODE firstedge;
} VERTEXNODE, ADJLIST[MAXVEX];

typedef struct AdjGraph
{
	ADJLIST adjList;
	int numVertexes, numEdges;
} GRAPHADJLIST, * PGRAPHADJLIST;

int Topological_Sort(PGRAPHADJLIST G);
void Init_AdjList(PGRAPHADJLIST * graphadjlist);

int main(void)
{
	PGRAPHADJLIST graphadjlist;
	
	Init_AdjList(&graphadjlist);
	
	if (!Topological_Sort(graphadjlist))
	{
		printf("Õÿ∆À≈≈–Ú ß∞‹");
	}
	printf("\n");


	system("pause");
	return 0;
}

int Topological_Sort(PGRAPHADJLIST G)
{
	int i, j, top, gettop, count;
	int * stack;
	PEDGENODE e;

	count = 0;

	stack = (int *)malloc(sizeof(int)*MAXVEX);
	top = 0;

	for (i=0; i<G->numVertexes; i++)
	{
		if (!G->adjList[i].in)
		{
			stack[top++] = i;
		}
	}
	
	while (top)
	{
		gettop = stack[--top];
		printf("%d  ", G->adjList[gettop].vex);
		count++;

		for (e=G->adjList[gettop].firstedge; e; e=e->next)
		{
			j = e->adjvex;
			if (!--G->adjList[j].in)
			{
				stack[top++] = j;
			}
		}
	}
	if (count < G->numVertexes)
	{
		return 0;
	}
	else
	{
		return 1;

	}
}

void Init_AdjList(PGRAPHADJLIST * graphadjlist)
{
	int i;
	PEDGENODE e;
	*graphadjlist = (PGRAPHADJLIST)malloc(sizeof(GRAPHADJLIST));
	(*graphadjlist)->numVertexes = MAXVEX;
	(*graphadjlist)->numEdges = 19;
	

	for (i=0; i<(*graphadjlist)->numVertexes; i++)
	{
		(*graphadjlist)->adjList[i].vex = i+1;
	}
	
	(*graphadjlist)->adjList[0].in = 0;
	(*graphadjlist)->adjList[1].in = 2;
	(*graphadjlist)->adjList[2].in = 2;
	(*graphadjlist)->adjList[3].in = 2;
	(*graphadjlist)->adjList[4].in = 1;
	(*graphadjlist)->adjList[5].in = 1;
	(*graphadjlist)->adjList[6].in = 3;
	(*graphadjlist)->adjList[7].in = 1;
	(*graphadjlist)->adjList[8].in = 1;
	(*graphadjlist)->adjList[9].in = 2;
	(*graphadjlist)->adjList[10].in = 1;
	(*graphadjlist)->adjList[11].in = 1;
	(*graphadjlist)->adjList[12].in = 0;
	(*graphadjlist)->adjList[13].in = 1;
	(*graphadjlist)->adjList[14].in = 1;

	(*graphadjlist)->adjList[1].firstedge = NULL;
	(*graphadjlist)->adjList[4].firstedge = NULL;
	(*graphadjlist)->adjList[5].firstedge = NULL;
	(*graphadjlist)->adjList[6].firstedge = NULL;
	(*graphadjlist)->adjList[7].firstedge = NULL;
	(*graphadjlist)->adjList[8].firstedge = NULL;
	(*graphadjlist)->adjList[11].firstedge = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[0].firstedge = e;
	(*graphadjlist)->adjList[0].firstedge->adjvex = 1;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[0].firstedge->next = e;
	(*graphadjlist)->adjList[0].firstedge->next->adjvex = 2;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[0].firstedge->next->next = e;
	(*graphadjlist)->adjList[0].firstedge->next->next->adjvex = 3;
	(*graphadjlist)->adjList[0].firstedge->next->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[2].firstedge = e;
	(*graphadjlist)->adjList[2].firstedge->adjvex = 5;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[2].firstedge->next = e;
	(*graphadjlist)->adjList[2].firstedge->next->adjvex = 6;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[2].firstedge->next->next = e;
	(*graphadjlist)->adjList[2].firstedge->next->next->adjvex = 8;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[2].firstedge->next->next->next = e;
	(*graphadjlist)->adjList[2].firstedge->next->next->next->adjvex = 9;
	(*graphadjlist)->adjList[2].firstedge->next->next->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[3].firstedge = e;
	(*graphadjlist)->adjList[3].firstedge->adjvex = 6;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[3].firstedge->next = e;
	(*graphadjlist)->adjList[3].firstedge->next->adjvex = 7;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[3].firstedge->next->next = e;
	(*graphadjlist)->adjList[3].firstedge->next->next->adjvex = 9;
	(*graphadjlist)->adjList[3].firstedge->next->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[9].firstedge = e;
	(*graphadjlist)->adjList[9].firstedge->adjvex = 6;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[9].firstedge->next = e;
	(*graphadjlist)->adjList[9].firstedge->next->adjvex = 10;
	(*graphadjlist)->adjList[9].firstedge->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[10].firstedge = e;
	(*graphadjlist)->adjList[10].firstedge->adjvex = 11;
	(*graphadjlist)->adjList[10].firstedge->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[12].firstedge = e;
	(*graphadjlist)->adjList[12].firstedge->adjvex = 3;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[12].firstedge->next = e;
	(*graphadjlist)->adjList[12].firstedge->next->adjvex = 13;
	(*graphadjlist)->adjList[12].firstedge->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[13].firstedge = e;
	(*graphadjlist)->adjList[13].firstedge->adjvex = 1;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[13].firstedge->next = e;
	(*graphadjlist)->adjList[13].firstedge->next->adjvex = 2;
	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[13].firstedge->next->next = e;
	(*graphadjlist)->adjList[13].firstedge->next->next->adjvex = 14;
	(*graphadjlist)->adjList[13].firstedge->next->next->next = NULL;

	e = (PEDGENODE)malloc(sizeof(EDGENODE));
	(*graphadjlist)->adjList[14].firstedge = e;
	(*graphadjlist)->adjList[14].firstedge->adjvex = 4;
	(*graphadjlist)->adjList[14].firstedge->next = NULL;
}