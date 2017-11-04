# include <stdio.h>
# include <stdlib.h>

# define MAXVEX 9
# define INFINITY 65535

typedef struct MGraph
{
	int numVertexes;
	int matrix[MAXVEX][MAXVEX];
} MGRAPH, * PMGRAPH;

void ShortestPath_Floyd(PMGRAPH G, int (*P)[MAXVEX], int (*D)[MAXVEX]);
void Init_MGraph(PMGRAPH * G);

int main(void)
{
	PMGRAPH G;
	int D[MAXVEX][MAXVEX];
	int P[MAXVEX][MAXVEX];
	int i, j;

	Init_MGraph(&G);

	ShortestPath_Floyd(G, P, D);

	printf("\nD:\n");
	for (i=0; i<G->numVertexes; i++)
	{
		for (j=0; j<G->numVertexes; j++)
			printf("%-3d", D[i][j]);
		printf("\n");
	}
	printf("\nP:\n");
	for (i=0; i<G->numVertexes; i++)
	{
		for (j=0; j<G->numVertexes; j++)
			printf("%-3d", P[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}

void ShortestPath_Floyd(PMGRAPH G, int (*P)[MAXVEX], int (*D)[MAXVEX])
{
	int i, j, k;

	for (i=0; i<G->numVertexes; i++)
		for (j=0; j<G->numVertexes; j++)
		{
			D[i][j] = G->matrix[i][j];
			P[j][i] = i;
		}

	for (k=0; k<G->numVertexes; k++)
		for (i=0; i<G->numVertexes; i++)
			for (j=0; j<G->numVertexes; j++)
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
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