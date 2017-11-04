# include <stdio.h>
# include <stdlib.h>

enum PointerTag {Link, Thread};
typedef char ElemType;
typedef struct BiThrNode
{
	ElemType data;
	struct BiThrNode * lchild, * rchild;
	PointerTag ltag, rtag;
} BITHRNODE, * BITHRTREE;

BITHRTREE pre;

void Create_BiTree(BITHRTREE * T);
void InorderThreading(BITHRTREE T, BITHRTREE * P);
void InThreading(BITHRTREE T);
void InorderTraverse(BITHRTREE T);

int main(void)
{
	BITHRTREE T=NULL, P;

	Create_BiTree(&T);

	InorderThreading(T, &P);

	printf("中序遍历输出结果是：");
	InorderTraverse(P);
	printf("\n");
	

	system("pause");
	return 0;
}

void Create_BiTree(BITHRTREE * T)
{
	ElemType c;
	
	scanf_s("%c", &c, 1);
	if (' ' == c)
	{
		*T = NULL;	
	}
	else
	{
		*T = (BITHRTREE)malloc(sizeof(BITHRNODE));
		(*T)->data = c;
		(*T)->ltag = (*T)->rtag = Link;

		Create_BiTree(&(*T)->lchild);
		Create_BiTree(&(*T)->rchild);
	}
}

void InorderThreading(BITHRTREE T, BITHRTREE * P)
{
	*P = (BITHRTREE)malloc(sizeof(BITHRNODE));
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
		pre->rtag = Thread;
		pre->rchild = *P;
		(*P)->rchild = pre;
	}
}

void InThreading(BITHRTREE T)
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

void InorderTraverse(BITHRTREE T)
{
	BITHRTREE p = T->lchild;

	while (p != T)
	{
		while (p->ltag == Link)
			p = p->lchild;

		printf("%c ", p->data);

		while (p->rtag==Thread && p->rchild!=T)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		
		p = p->rchild;	
	}
	return ;
}
