# include <stdio.h>
# include <stdlib.h>

/*
	2016年12月27日08:21:48
	2016年12月27日08:35:36
	耗时：13分钟48秒
*/

enum PointerNag {Link, Thread};
typedef char ElemType;
typedef struct BiThrNode
{
	ElemType data;
	struct BiThrNode * lchild, * rchild;
	PointerNag ltag, rtag;
} BITHRNODE, * BITHRTREE;

BITHRTREE pre;

void CreateBiThrTree(BITHRTREE * T);
void InThreading(BITHRTREE T);
void InOrderThreading(BITHRTREE T, BITHRTREE * P);
void InOrderTraverse(BITHRTREE T);

int main(void)
{
	BITHRTREE T, P;
	T = P = NULL;

	CreateBiThrTree(&T);

	InOrderThreading(T, &P);

	printf("中序遍历输出结果是：");
	InOrderTraverse(P);
	printf("\n");

	system("pause");
	return 0;
}

void CreateBiThrTree(BITHRTREE * T)
{
	ElemType c;

	c = getchar();

	if (' ' == c)
		*T = NULL;
	else
	{
		*T = (BITHRTREE)malloc(sizeof(BITHRNODE));
		if (NULL == *T)
		{
			printf("ERROR!\n");
			system("pause");
			exit(0);
		}
		(*T)->data = c;
		(*T)->ltag = (*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

void InThreading(BITHRTREE T)
{
	if (T)
	{
		InThreading(T->lchild);

		if (!T->lchild)
		{
			T->ltag  = Thread;
			T->lchild  = pre;
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

void InOrderThreading(BITHRTREE T, BITHRTREE * P)
{
	*P = (BITHRTREE)malloc(sizeof(BITHRNODE));
	if (NULL == *P)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	(*P)->ltag = Link;
	(*P)->rtag = Thread;
	(*P)->rchild = *P;

	if (!T)
		(*P)->lchild = *P;
	else
	{
		(*P)->lchild = T;
		pre = *P;
		InThreading(T);
		(*P)->rchild = pre;
		pre->ltag = Thread;
		pre->rchild = *P;
	}
}

void InOrderTraverse(BITHRTREE T)
{
	BITHRTREE p = T->lchild;

	while (T != p)
	{
		while (p->ltag == Link)
			p = p->lchild;

		printf("%c", p->data);

		while (p->rtag==Thread && p->rchild!=T)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}