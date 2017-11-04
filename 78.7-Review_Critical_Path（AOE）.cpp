# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 9
# define TRUE 1
# define FALSE 0

typedef int Status;

typedef struct EdgeNode
{
	int adjvex, weight;
	struct EdgeNode * next;
} EdgeNode, * PEdgeNode;

typedef struct VertexNode
{
	int vex;
	int in;
	PEdgeNode firstedge;
} VerTexNode, AdjList[MAXVEX];

typedef struct GraphAdjList
{
	AdjList adjList;
	int numEdges, numVertexes;
} GraphAdjList, * PGraphAdjList;

Status Topological_Sort(PGraphAdjList Gl);
Status Critical_Path(PGraphAdjList Gl);
void Init_AdjList(PGraphAdjList * GL);

int * stack2, top2;
int * ltv, * etv;

int main(void)
{
	PGraphAdjList GL;

	Init_AdjList(&GL);

	Critical_Path(GL);

// 	printf("\netv: ");
// 	for (int i=0; i<GL->numVertexes; i++)
// 		printf("%d ", etv[i]);
// 	printf("\nltv: ");
// 	for (int i=0; i<GL->numVertexes; i++)
// 		printf("%d ", ltv[i]);
// 	printf("\n");

	system("pause");
	return 0;
}

Status Topological_Sort(PGraphAdjList GL)
{
	int i, j, count, top, gettop;
	PEdgeNode e;

	int * stack = (int *)malloc(sizeof(int)*MAXVEX);
	etv = (int *)malloc(sizeof(int)*MAXVEX);
	stack2 = (int *)malloc(sizeof(int)*MAXVEX);
	if (!stack && !ltv && !stack2)
	{
		printf("Failed to allocate dynamic memory space!\n");
		system("pause");
		exit(0);
	}
	
	top = 0;
	for (i=0; i<GL->numVertexes; i++)
	{
		if (!GL->adjList[i].in)
			stack[top++] = i;

		etv[i] = 0;
	}

	top2 = count = 0;
	while (top)
	{
		gettop = stack[--top];
		count++;
		stack2[top2++] = gettop;

		for (e=GL->adjList[gettop].firstedge; e; e=e->next)
		{
			j = e->adjvex;

			if (!(--GL->adjList[j].in))
				stack[top++] = j;

			if (etv[gettop] + e->weight > etv[j])
				etv[j] = etv[gettop] + e->weight;
		}
	}

	if (count < GL->numVertexes)
		return FALSE;
	else
		return TRUE;
}

Status Critical_Path(PGraphAdjList GL)
{
	int i, gettop2, j, ete, lte, flag;
	PEdgeNode e;

	ltv = (int *)malloc(sizeof(int)*MAXVEX);
	if (!ltv)
	{
		printf("Failed to allocate dynamic memory space!\n");
		system("pause");
		exit(0);
	}

	if (Topological_Sort(GL))
		flag = TRUE;
	else
		flag = FALSE;

	for (i=0; i<GL->numVertexes; i++)
		ltv[i] = etv[GL->numVertexes-1];

	while (0 != top2)
	{
		gettop2 = stack2[--top2];

		for (e=GL->adjList[gettop2].firstedge; e; e=e->next)
		{
			j = e->adjvex;

			if (ltv[j] - e->weight < ltv[gettop2])
				ltv[gettop2] = ltv[j] - e->weight;
		}
	}

	for (i=0; i<GL->numVertexes; i++)
	{
		for (e=GL->adjList[i].firstedge; e; e=e->next)
		{
			j = e->adjvex;
			ete = etv[i];
			
			lte = ltv[j] - e->weight;

//			printf("(v%d, v%d), ete:%d, lte:%d\n",GL->adjList[i].vex, GL->adjList[j].vex, ete, lte);
			
			if (ete == lte)
				printf("(v%d,v%d), weight:%d\n", GL->adjList[i].vex, GL->adjList[j].vex, e->weight);
		}
	}

	if (flag)
		return TRUE;
	else
		return FALSE;
}

void Init_AdjList(PGraphAdjList * GL)
{
	EdgeNode * e;

	*GL = (PGraphAdjList)malloc(sizeof(GraphAdjList));
	(*GL)->numEdges =  11;
	(*GL)->numVertexes = MAXVEX;

	(*GL)->adjList[0].in = 0;
	(*GL)->adjList[1].in = 1;
	(*GL)->adjList[2].in = 1;
	(*GL)->adjList[3].in = 1;
	(*GL)->adjList[4].in = 2;
	(*GL)->adjList[5].in = 1;
	(*GL)->adjList[6].in = 1;
	(*GL)->adjList[7].in = 2;
	(*GL)->adjList[8].in = 2;

	for (int i=0; i<(*GL)->numVertexes; i++)
		(*GL)->adjList[i].vex = i+1;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[0].firstedge = e;
	e->adjvex = 1; e->weight = 6;
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[0].firstedge->next = e;
	e->adjvex = 2; e->weight = 4;
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[0].firstedge->next->next = e;
	e->adjvex = 3; e->weight = 5; e->next = NULL;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[1].firstedge = e;
	e->adjvex = 4; e->weight = 1; e->next = NULL;
	
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[2].firstedge = e;
	e->adjvex = 4; e->weight = 1; e->next = NULL;
	
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[3].firstedge = e;
	e->adjvex = 5; e->weight = 2; e->next = NULL;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[4].firstedge = e;
	e->adjvex = 6; e->weight = 7;
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[4].firstedge->next = e;
	e->adjvex = 7; e->weight = 5; e->next = NULL;
	
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[5].firstedge = e;
	e->adjvex = 7; e->weight = 4; e->next = NULL;

	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[6].firstedge = e;
	e->adjvex = 8; e->weight = 2; e->next = NULL;
	
	e = (EdgeNode *)malloc(sizeof(EdgeNode));
	(*GL)->adjList[7].firstedge = e;
	e->adjvex = 8; e->weight = 4; e->next = NULL;

	(*GL)->adjList[8].firstedge = NULL;
}