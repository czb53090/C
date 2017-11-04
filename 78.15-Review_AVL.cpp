/*
	测试数据：
		5 9 15 7 77 6 3 4 32 1 8 2
*/
# include <stdio.h>
# include <stdlib.h>

# define LH 1
# define EH 0
# define RH -1
# define TRUE 1
# define FALSE 0
# define MAXSIZE 12

typedef int Status;
typedef int ElementType;

typedef struct BiTNode
{
	int bf;
	ElementType data;
	struct BiTNode * lchild;
	struct BiTNode * rchild;
} BITNODE, * PBITNODE;

// 平衡二叉排序树：Self-Balancing/Height-Balanced Bianry_Search_Tree
void Create_AVL(PBITNODE * T);
Status Insert_AVL(PBITNODE * T, ElementType data, int * taller);
void Left_Balance(PBITNODE * T);
void Right_Balance(PBITNODE * T);
void Left_Rotate(PBITNODE * P);
void Right_Rotate(PBITNODE * P);
void Traverse_AVL(PBITNODE T);

int main(void)
{
	PBITNODE T;

	Create_AVL(&T);

	Traverse_AVL(T);
	printf("\n");

	system("pause");
	return 0;
}

void Create_AVL(PBITNODE * T)
{
	int i, taller;
	ElementType data;

	*T = NULL;

	for (i=0; i<MAXSIZE; i++)
	{
		taller = FALSE;
		scanf("%d", &data);
		Insert_AVL(T, data, &taller);
	}
}

Status Insert_AVL(PBITNODE * T, ElementType data, int * taller)
{
	if (!*T)
	{
		*T = (PBITNODE)malloc(sizeof(BITNODE));

		(*T)->data = data;
		(*T)->bf = EH;
		(*T)->lchild = (*T)->rchild = NULL;

		*taller = TRUE;

		return TRUE;
	}
	else
	{
		if (data == (*T)->data)
		{
			*taller = FALSE;
			return FALSE;
		}
		else if (data < (*T)->data)
		{
			if (!Insert_AVL(&(*T)->lchild, data, taller))
				return FALSE;
			
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					Left_Balance(T);
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = TRUE;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				}
			}
		}
		else
		{
			if (!Insert_AVL(&(*T)->rchild, data, taller))
				return FALSE;
			
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = FALSE;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = TRUE;
					break;
				case RH:
					Right_Balance(T);
					*taller = FALSE;
					break;
				}
			}
		}
	}

	return TRUE;
}

void Left_Balance(PBITNODE * T)
{
	PBITNODE L, Lr;

	L = (*T)->lchild;

	switch (L->bf)
	{
	case LH:
		(*T)->bf = L->bf = EH;
		Right_Rotate(T);
		break;
	case RH:
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}

		Lr->bf = EH;
		Left_Rotate(&(*T)->lchild);
		Right_Rotate(T);
		break;
	}
}
void Right_Balance(PBITNODE * T)
{
	PBITNODE R, Rl;
	
	R = (*T)->rchild;
	
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		Left_Rotate(T);
		break;
	case LH:
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		}
		
		Rl->bf = EH;
		Right_Rotate(&(*T)->rchild); //不能是&L，因为修改L的值对T树毫无影响
		Left_Rotate(T);
		break;
	}
}

void Left_Rotate(PBITNODE * P)
{
	PBITNODE R = (*P)->rchild;

	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

void Right_Rotate(PBITNODE * P)
{
	PBITNODE L = (*P)->lchild;

	(*P)->lchild = L->rchild;
	L->rchild = *P;
	*P = L;
}

void Traverse_AVL(PBITNODE T)
{
	if (T)
	{
		Traverse_AVL(T->lchild);
		printf("%d ", T->data);
		Traverse_AVL(T->rchild);
	}
}