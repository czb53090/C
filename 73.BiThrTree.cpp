# include <stdio.h>
# include <stdlib.h>

typedef enum {Link, Thread} PointerNag;

typedef char ElemType;
typedef struct ThrNode
{
	ElemType data;
	int ltag;
	int rtag;
	struct ThrNode * lchild;
	struct ThrNode * rchild;
} THRNODE, * THRTREE;

THRTREE pre;

void CreatThrTree(THRTREE * T);
void InThreading(THRTREE T);
void InOrderThreading(THRTREE T, THRTREE * P);
void InOrderTraverse(THRTREE T);

int main(void)
{
	THRTREE T=NULL, P=NULL;

	CreatThrTree(&T);
	InOrderThreading(T, &P);
	printf("中序遍历输出结果为：");
	InOrderTraverse(P);
	printf("\n");

	system("pause");
	return 0;
}

void CreatThrTree(THRTREE * T)
{
	ElemType c;

	c = getchar();
	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (THRTREE)malloc(sizeof(THRNODE));
		if (NULL == (*T))
		{
			printf("error!");
			system("pause");
			exit(0);
		}
		(*T)->data = c;
		(*T)->ltag = (*T)->rtag = Link;
		CreatThrTree(&(*T)->lchild);
		CreatThrTree(&(*T)->rchild);
	}
}

void InThreading(THRTREE T)
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
}

void InOrderThreading(THRTREE T, THRTREE * P)
{
	*P = (THRTREE)malloc(sizeof(THRNODE));
	if (NULL == P)
	{
		printf("error!");
		system("pause");
		exit(0);
	}
	
	(*P)->ltag = Link;
	(*P)->rtag = Thread;
	(*P)->rchild = *P;

	if (!T)
	{
		(*P)->lchild = *P;
	}
	else
	{
		(*P)->lchild = T;
		pre = *P;
		InThreading(T);
		pre->rchild = *P;
		pre->rtag = Thread;
		(*P)->rchild = pre;
	}
}

void InOrderTraverse(THRTREE T)
{
	THRTREE p = T->lchild;

	while(p != T)
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}

		printf("%c", p->data);

		while (p->rtag==Thread && p->rchild!=T)
		{	
			p = p->rchild;
			printf("%c", p->data);
		}

		p = p->rchild;
	}
}