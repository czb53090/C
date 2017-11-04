# include <stdio.h>
# include <stdlib.h>

enum Pointertag{Link, Thread};

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode * lchild, * rchild;
	Pointertag ltag, rtag;
} BITNODE, * BITREE;

BITREE pre;

void Create_BiTree(BITREE * T);
void InOrderThreading(BITREE T, BITREE * P);
void InThreading(BITREE T);
void Traverse_BiTree(BITREE P);

int main(void)
{
	BITREE T, P;

	Create_BiTree(&T);

	InOrderThreading(T, &P);

	printf("中序遍历结果为：\n");
	Traverse_BiTree(P);
	printf("\n");

	system("pause");
	return 0;
}

void Create_BiTree(BITREE * T)
{
	ElemType c;

	c = getchar();
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BITREE)malloc(sizeof(BITNODE));
		if (*T == NULL)
		{
			printf("Dynamic allocation of internal failure from space!");
			system("pause");
			exit(EXIT_FAILURE);
		}
		(*T)->data = c;
		(*T)->ltag = (*T)->rtag = Link;

		Create_BiTree(&(*T)->lchild);
		Create_BiTree(&(*T)->rchild);
	}
}

void InOrderThreading(BITREE T, BITREE * P)
{
	*P = (BITREE)malloc(sizeof(BITNODE));
	if (*P == NULL)
	{
		printf("Dynamic allocation of internal failure from space!");
		system("pause");
		exit(EXIT_FAILURE);
	}

	(*P)->ltag = Link;
	(*P)->rtag = Thread;
	(*P)->rchild = *P;

	if (!T)ABDHA
	{
		(*P)->lchild = *P;
	}
	else
	{
		(*P)->lchild = T;
		pre = *P;

		InThreading(T);

		pre->rtag = Thread;
		pre->rchild = *P;
		(*P)->rchild = pre;
	}
}

void InThreading(BITREE T)
{
	if (T)
	{
		InThreading(T->lchild);

		if (!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		InThreading(T->rchild);	
	}

	return;
}

void Traverse_BiTree(BITREE P)
{
	BITREE T = P->lchild;

	while (T != P)
	{
		while (T->ltag==Link)
			T = T->lchild;

		printf("%c ", T->data);

		while (T->rtag==Thread && T->rchild!=P)
		{
			T = T->rchild;
			printf("%c ", T->data);
		}

		T = T->rchild;
	}

	return;
}