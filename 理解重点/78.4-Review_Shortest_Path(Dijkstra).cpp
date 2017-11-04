# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 9
# define INFINITY 65535

typedef struct MGraph
{
	int numVertexes;
	int matrix[MAXVEX][MAXVEX];
} MGRAPH, * PMGRAPH;

void ShortestPath_Dijkstra(PMGRAPH G, int vex, int * D, int * P);
void Init_MGraph(PMGRAPH * G);

int main(void)
{
	int D[MAXVEX];
	int P[MAXVEX];
	PMGRAPH G;

	Init_MGraph(&G);

	ShortestPath_Dijkstra(G, 0, D, P);

	printf("Index©§  D ©§  P\n ©¥©¥©ï©¥©¥©ï©¥©¥\n");
	for (int i=0; i<G->numVertexes; i++)
	{
		printf("  %d  ©§%3d ©§%3d\n", i, D[i], P[i]);
	}

	system("pause");
	return 0;
}

void ShortestPath_Dijkstra(PMGRAPH G, int vex, int * D, int * P)
{
	int i, j, k, min;
	int final[MAXVEX];

	for (i=0; i<G->numVertexes; i++)
	{
		D[i] = G->matrix[vex][i];
		P[i] = 0;
		final[i] = 1;
	}
	final[vex] = D[vex] = 0;

	for (i=1; i<G->numVertexes; i++)
	{
		min = INFINITY;
		for (j=0; j<G->numVertexes; j++)
			if (final[j] && min>D[j])
			{
				min = D[j];
				k = j;
			}

		final[k] = 0;

		for (j=0; j<G->numVertexes; j++)
			if (final[j] && D[j]>min+G->matrix[k][j])
			{
				D[j] = min + G->matrix[k][j];
				P[j] = k;
			}
	}
}

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
		
		(*G)->matrix[0][1] = 1; (*G)->matrix[0][2] = 5;
		(*G)->matrix[1][0] = 1; (*G)->matrix[1][2] = 3; (*G)->matrix[1][3] = 7; (*G)->matrix[1][4] = 5;
		(*G)->matrix[2][0] = 5; (*G)->matrix[2][1] = 3; (*G)->matrix[2][4] = 1; (*G)->matrix[2][5] = 7;
		(*G)->matrix[3][1] = 7; (*G)->matrix[3][4] = 2; (*G)->matrix[3][6] = 3;
		(*G)->matrix[4][1] = 5; (*G)->matrix[4][2] = 1; (*G)->matrix[4][3] = 2; (*G)->matrix[4][5] = 3; (*G)->matrix[4][6] = 6; (*G)->matrix[4][7] = 9;
		(*G)->matrix[5][2] = 7; (*G)->matrix[5][4] = 3; (*G)->matrix[5][7] = 5;
		(*G)->matrix[6][3] = 3; (*G)->matrix[6][4] = 6; (*G)->matrix[6][7] = 2; (*G)->matrix[6][8] = 7;
		(*G)->matrix[7][4] = 9; (*G)->matrix[7][5] = 5; (*G)->matrix[7][6] = 2; (*G)->matrix[7][8] = 4;
		(*G)->matrix[8][6] = 7; (*G)->matrix[8][7] = 4;
}