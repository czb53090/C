#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	int i, j; // 该非零元的行和列下标
	ElemType e;
	struct Node * right, * down; // 该非零元所在行表和列表的后继链域
}Node, * PNode;

typedef struct HeadNode
{
	PNode * rhead, * chead; // 行和列链表头指针向量基址
	int mu, nu, tu; //稀疏矩阵的行数、列数和非零元个数
}HeadNode, * HeadList;

int main(void)
{
	
	system("pause");
	return 0;	
}

Status CreateSMatrix_OL(HeadList M)
{
	int m, n, t, i, j;
	ElemType e;
	PNode p, q;

	if (M)
		free M;
	scanf("%d %d %d", &m, &n, &t);
	M->mu = m;
	M->nu = n;
	M->tu = t;
	
	if (!(M->rhead = (PNode *)malloc((m+1)*sizeof(PNode))))
		exit(-1);
	if (!(M->chead = (PNode *)malloc((n+1)*sizeof(PNode))))
		exit(-1);

	for (i=0; i<m+1; i++)
		M->rhead[i] = NULL;

	for (scanf("%d %d %d", &i, &j, &e); i!=0; scanf("%d %d %d", &i, &j, &e))
	{
		if (!(p = (PNode)malloc(sizeof(PNode))))
			exit(-1);
		p->i = i;
		p->j = j;
		p->e = e;
		if (NULL==M->rhead[i] || M->rhead[i]->j>j)
		{
			p->right = M->rhead[i];
			M->rhead[i] = p;
		}
		else
		{
			for (q=M->rhead[i]; (q->right)&&q->right->j<j; q=q->right)
				;
			p->right = q->right;
			q->right = p;
		}
		if (NULL==M->chead[j] || M->chead[j]->i>i)
		{
			p->down = M->chead[j];
			M->chead[j] = p;
		}
		else
		{
			for (q=M->chead[j]; (q->down)&&q->down->i<i; q=q->down)
				;
			p->down = q->down;
			q->down = p;
		}
	}
}