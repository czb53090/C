# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 9
# define INFINITY 65535

typedef struct MGraph
{
	int matrix[MAXVEX][MAXVEX];
	int numVertexes;
} MGRAPH, * PMGRAPH;

void MiniSpanTree_Prim(PMGRAPH G);
void InitGraph(PMGRAPH * G);

int main(void)
{
	PMGRAPH G;

	InitGraph(&G);

	MiniSpanTree_Prim(G);

	system("pause");
	return 0;
}

void MiniSpanTree_Prim(PMGRAPH G)
{
	int i, j, k, min;
	int lowcost[MAXVEX];
	int adjvex[MAXVEX];

	lowcost[0] = adjvex[0] = 0;
	for (i=1; i<G->numVertexes; i++)
	{
		lowcost[i] = G->matrix[0][i];
		adjvex[i] = 0;
	}

	for (i=1; i<G->numVertexes; i++)
	{
		k = 0;
		min = INFINITY;
		for (j=1; j<G->numVertexes; j++)
			if (lowcost[j] && lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
		
		printf("(%d,%d)\n", adjvex[k], k);
		lowcost[k] = 0;

		for (j=1; j<G->numVertexes; j++)
		{
			if (lowcost[j] && G->matrix[k][j]<lowcost[j] && G->matrix[k][j])
			{
				lowcost[j] = G->matrix[k][j];
				adjvex[j] = k;
			}
		}
	}
}

void InitGraph(PMGRAPH * G)
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