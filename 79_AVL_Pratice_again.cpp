/*
  ≤‚ ‘ ˝æ›£∫
45 1 7 19 34 20 55 78 4 14 87 100 200 35 22
*/
# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 15

# define LH 1
# define EH 0
# define RH -1

# define TRUE 1
# define FALSE 0

typedef int Status;
typedef int ElementType;

typedef struct BiTNode
{
	ElementType data;
	int bf;
	struct BiTNode * lchild;
	struct BiTNode * rchild;
} BITNODE, * PBITNODE;

void Create_AVL(PBITNODE * T);
Status Insert_AVL(PBITNODE * T, int key, int * taller);
void Left_Balance(PBITNODE * T);
void Left_Rotate(PBITNODE * P);
void Right_Balance(PBITNODE * T);
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
	int i, key, taller;
	*T = NULL;

	for (i=0; i<MAXSIZE; i++)
	{
		scanf("%d", &key);
		Insert_AVL(T, key, &taller);
	}
}

Status Insert_AVL(PBITNODE * T, int key, int * taller)
{
	if (!*T)
	{
		*T = (PBITNODE)malloc(sizeof(BITNODE));
		(*T)->data = key;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;

		return TRUE;
	}
	else
	{
		if (key == (*T)->data)
		{
			*taller = FALSE;
			return FALSE;
		}
		else if (key < (*T)->data)
		{
			if (!Insert_AVL(&(*T)->lchild, key, taller))
				return TRUE;
			
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
					*taller  = TRUE;
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
			if (!Insert_AVL(&(*T)->rchild, key, taller))
				return TRUE;
			
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
					*taller  = TRUE;
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
		}
		break;
	}
}
void Left_Rotate(PBITNODE * P)
{
	PBITNODE R;

	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

void Right_Balance(PBITNODE * T)
{
	PBITNODE R, Rl;
	
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		Right_Rotate(T);
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
		}
		break;
	}
}
void Right_Rotate(PBITNODE * P)
{
	PBITNODE L;
	
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
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