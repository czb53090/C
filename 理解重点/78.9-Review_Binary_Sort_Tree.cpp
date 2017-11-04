/*
	≤‚ ‘ ˝æ›£∫
		70 67 105 46 100 115 99 104 103 110 112 108
*/

# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define MAXSIZE 12

typedef int ElementType;
typedef int Status;

typedef struct BiTNode
{
	ElementType data;
	struct BiTNode * lchild, * rchild;
} BITNODE, * BITREE;

Status SearchBST(BITREE T, ElementType key, BITREE f, BITREE * p);
Status InsertBST(BITREE * T, ElementType key);
Status DeleteBST(BITREE T, ElementType key);
Status Delete(BITREE T);
void CreateBST(BITREE * T);
void TraverseBST(BITREE T);

int main(void)
{
	BITREE T;

	CreateBST(&T);

	printf("\n");
	TraverseBST(T);
	printf("\n");

	DeleteBST(T, 105);

	printf("\n");
	TraverseBST(T);
	printf("\n");

	system("pause");
	return 0;
}

Status SearchBST(BITREE T, ElementType key, BITREE f, BITREE * p)
{
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)
	{
		*p = T;
		return TRUE;
	}
	else if (key  < T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
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
			*T = s;
		else if(key < p->data)
			p->lchild = s;
		else
			p->rchild = s;

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status DeleteBST(BITREE T, ElementType key)
{
	if (!T)
	{
		return FALSE;
	}
	else if (key == T->data)
	{
		return Delete(T);
	}
	else if (key  < T->data)
	{
		return DeleteBST(T->lchild, key);
	}
	else
	{
		return DeleteBST(T->rchild, key);
	}
}

Status Delete(BITREE T)
{
	BITREE q, s;

	if (!T->lchild && !T->rchild)
	{
		free(T);
		T = NULL;
	}
	else if (!T->rchild)
	{
		q = T;
		T = T->lchild;
		free(q);
		q = NULL;
	}
	else if (!T->lchild)
	{
		q = T;
		T = T->rchild;
		free(q);
		q = NULL;
	}
	else
	{
		q = T;
		s = T->lchild;

		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}

		T->data = s->data;
		
		if (q != T)
		{
			
			q->rchild = s->lchild;
			s = NULL;
		}
		else
		{
			q->lchild = s->lchild;
			q = NULL;
		}

		free(s);
	}
	return TRUE;
}

void CreateBST(BITREE * T)
{
	int i, key;

	*T = NULL;
	for (i=0; i<MAXSIZE; i++)
	{
		scanf("%d", &key);
		if(!InsertBST(T, key))
			printf("failed to insert %d\n", key);
	}
}

void TraverseBST(BITREE T)
{
	if (T)
	{
		TraverseBST(T->lchild);
		printf("%d ", T->data);
		TraverseBST(T->rchild);
	}
}

