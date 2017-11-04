# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 9
# define MAXEDGE 15
# define INFINITY 65535

typedef struct MGraph
{
	int numVertexes;
	int matrix[MAXVEX][MAXVEX];
} MGRAPH, * PMGRAPH;

typedef struct Edge
{
	int begin, end, weight;
} EDGE, * PEDGE, EDGES[MAXEDGE];

int Find_NextVex(int * parent, int n);
void MiniSpanTree_Kruskal(PMGRAPH G, PEDGE Edges, int numEdges);
void Create_Edges_Array(PMGRAPH * G, PEDGE Edges, int * numEdges);
void Init_MGraph(PMGRAPH * G);
void Change(PMGRAPH G, PEDGE edges, int * k);
void Sort(PEDGE edges, int numedge);

int main(void)
{
	EDGES Edges;
	PMGRAPH G;
	int numEdges;

	Create_Edges_Array(&G, Edges, &numEdges);

	MiniSpanTree_Kruskal(G, Edges, numEdges);

	system("pause");
	return 0;
}

//寻找顶点所在子树的最后一个顶点下标
int Find_NextVex(int * parent, int n)
{
	while (parent[n])
		n = parent[n];

	return n;
}

// Kruskal算法生成最小生成树
void MiniSpanTree_Kruskal(PMGRAPH G, PEDGE Edges, int numEdges)
{
	int parent[MAXVEX];
	int i, n, m;

	for (i=0; i<G->numVertexes; i++)
		parent[i] = 0;

	for (i=0; i<numEdges; i++)
	{
		n = Find_NextVex(parent, Edges[i].begin);
		m = Find_NextVex(parent, Edges[i].end);

		if (n != m)
		{
			parent[n] = m;
			printf("(%d,%d) weight:%d\n", Edges[i].begin, Edges[i].end, Edges[i].weight);
		}
	}
}

//生成边集数组
void Create_Edges_Array(PMGRAPH * G, PEDGE Edges, int * numEdges)
{
	Init_MGraph(G);
	*numEdges = 0;
	Change(*G, Edges, numEdges);
	Sort(Edges, *numEdges);
}

// 生成树的邻接矩阵
void Init_MGraph(PMGRAPH * G)
{
	int i, j;
	
	*G = (PMGRAPH)malloc(sizeof(MGRAPH));
	if (NULL == *G)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	
	(*G)->numVertexes = MAXVEX;
	
	for (i=0; i<MAXVEX; i++)
		for (j=0; j<MAXVEX; j++)
		{
			(*G)->matrix[i][j] = INFINITY;
			if (i == j)
				(*G)->matrix[i][j] = 0;
		}	
		
		(*G)->matrix[0][1] = 10; (*G)->matrix[0][5] = 11;
		(*G)->matrix[1][0] = 10; (*G)->matrix[1][2] = 18; (*G)->matrix[1][6] = 16; (*G)->matrix[1][8] = 12;
		(*G)->matrix[2][1] = 18; (*G)->matrix[2][3] = 22; (*G)->matrix[2][8] =  8;
		(*G)->matrix[3][2] = 22; (*G)->matrix[3][4] = 20; (*G)->matrix[3][6] = 24; (*G)->matrix[3][7] = 16; (*G)->matrix[3][8] = 21;
		(*G)->matrix[4][3] = 20; (*G)->matrix[4][5] = 26; (*G)->matrix[4][7] =  7;
		(*G)->matrix[5][0] = 11; (*G)->matrix[5][4] = 26; (*G)->matrix[5][6] = 17;
		(*G)->matrix[6][1] = 16; (*G)->matrix[6][3] = 24; (*G)->matrix[6][5] = 17; (*G)->matrix[6][7] = 19;
		(*G)->matrix[7][3] = 16; (*G)->matrix[7][4] =  7; (*G)->matrix[7][6] = 19;
		(*G)->matrix[8][1] = 12; (*G)->matrix[8][2] =  8; (*G)->matrix[8][3] = 21;
		
}

// 定义边集数组
void Change(PMGRAPH G, PEDGE edges, int * k)
{
	int i, j;
	
	for (i=0; i<G->numVertexes-1; i++)
		for (j=i+1; j<G->numVertexes; j++)
			if (G->matrix[i][j]!=INFINITY)
			{
				edges[*k].begin = i;
				edges[*k].end = j;
				edges[*k].weight = G->matrix[i][j];
				(*k)++;
			}					
}
// 对边集数组进行排序
void Sort(PEDGE edges, int numedge)
{
	int i, j;
	int item1, item2, item3;
	
	for (i=0; i<numedge-1; i++)
		for (j=0; j<numedge-i-1; j++)
			if (edges[j].weight > edges[j+1].weight)
			{
				item1 = edges[j].begin;
				item2 = edges[j].end;
				item3 = edges[j].weight;
				edges[j].begin = edges[j+1].begin;
				edges[j].end = edges[j+1].end;
				edges[j].weight = edges[j+1].weight;
				edges[j+1].begin = item1;
				edges[j+1].end = item2;
				edges[j+1].weight = item3;
			}
}
