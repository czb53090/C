/*
	2017年1月23日13:03:30
	2017年1月23日13:45:36

	测试数值：
		70 67 105 46 100 115 99 104 103 110 112 108
*/
# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 12
# define FALSE 0
# define TRUE 1

typedef int Status;
typedef int ElementType;

typedef struct BiTNode
{
	ElementType data;
	struct BiTNode * lchild;
	struct BiTNode * rchild;
} BITNODE, * BITREE;

Status SearchBST(BITREE F, ElementType key, BITREE f, BITREE * p);
Status InsertBST(BITREE * T, ElementType key);
void CreatBST(BITREE * T);
void InorderTraverse(BITREE T);
Status DeleteBST(BITREE T, ElementType key);
Status Delete(BITREE p);

int main(void)
{
	BITREE T;
	
	CreatBST(&T);
	InorderTraverse(T);
	printf("\n");

	DeleteBST(T, 105);
	InorderTraverse(T);
	printf("\n");

	system("pause");
	return 0;
}

Status SearchBST(BITREE F, ElementType key, BITREE f, BITREE * p)
{
	if (!F)
	{
		*p = f;
		return FALSE;
	}
	else if (key == F->data)
	{
		*p = F;
		return TRUE;
	}
	else if (key < F->data)
	{
		return SearchBST(F->lchild, key, F, p);
	}
	else
	{
		return SearchBST(F->rchild, key, F, p);
	}
}

Status InsertBST(BITREE * T, ElementType key)
{
	BITREE p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BITREE)malloc(sizeof(BITNODE));
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
		{
			*T = s;
		}
		else if (key < p->data)
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void CreatBST(BITREE * T)
{
	int i;
	ElementType key;

	*T = NULL;
	for (i=0; i<MAXSIZE; i++)
	{
		scanf("%d", &key);
		InsertBST(T, key);
	}
}

void InorderTraverse(BITREE T)
{
	if (T)
	{
		InorderTraverse(T->lchild);
		printf("%d ", T->data);
		InorderTraverse(T->rchild);
	}
}

Status DeleteBST(BITREE T, ElementType key)
{
	if (!T)
	{
		return FALSE;
	}
	else
	{
		if (key == T->data)
		{
			return Delete(T);
		}
		else if (key < T->data)
		{
			return DeleteBST(T->lchild, key);
		}
		else
		{
			return DeleteBST(T->rchild, key);
		}
	}
}
Status Delete(BITREE p)
{
	BITREE q, s;

	if (!p->lchild && p->rchild)
	{
		free(p);
	}
	else if (!p->lchild)
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild)
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else
	{
		s = p->lchild;
		q = p;

		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data;

		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;

		free(s);
	}
	return TRUE;
}