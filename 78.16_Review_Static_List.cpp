/*
	测试数据1：
10 10
1 2 3 4 5 7 16 9 18 19 
6 2 8 1 10 4 12 5 14 15

	测试数据2：
5 5 
1 2 3 4 5 
6 7 8 9 10
*/
# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 100

typedef int ElementType;

typedef struct Node
{
	int data;
	int cur;
} NODE, * PNODE, Static_List[MAXSIZE];

void Initialize_SL(PNODE SL);
int Malloc_SL(PNODE SL);
void Free_SL(int k, PNODE SL);
void Difference(PNODE SL);
int Insert_SL(PNODE SL, int pos, int e);
int LocateElem_SL(PNODE SL, int e);
void Traverse_SL(PNODE SL);

int main(void)
{
	Static_List SL;

	Initialize_SL(SL);

	Difference(SL);
	Traverse_SL(SL);

	Insert_SL(SL, 1, 6);
	Insert_SL(SL, 2, 66);
	Insert_SL(SL, 9, 666);
	Insert_SL(SL, 14, 6666);
	Traverse_SL(SL);

	system("pause");
	return 0;
}

void Initialize_SL(PNODE SL)
{
	int i;

	for (i=0; i<MAXSIZE-2; i++)
		SL[i].cur = i+1;
	SL[MAXSIZE-2].cur = 0;
	SL[MAXSIZE-1].cur = 1;
}

int Malloc_SL(PNODE SL)
{
	int i = SL[0].cur;
	if (SL[0].cur)
		SL[0].cur = SL[i].cur;

	return i;
}

void Free_SL(int k, PNODE SL)
{
	SL[k].cur = SL[0].cur;
	SL[0].cur = k;
}

//创建两个链表La，Lb并合并，如果相同则删除，不同则合并
void Difference(PNODE SL)
{
	int i, j, k, m, n, e;

	//输入La，Lb的表长
	scanf("%d %d", &m, &n);

	while (m--)
	{
		scanf("%d", &e);
		i = Malloc_SL(SL);

		if (i)
			SL[i].data = e;
		else
		{
			printf("\nStatic List is full!\n");
			system("pause");
			exit(-1);
		}
	}
	SL[i].cur = 0;

	while (n--)
	{
		scanf("%d", &e);

		i = SL[MAXSIZE-1].cur;
		while (SL[i].data!=e && i)
		{
			k = i;
			i = SL[i].cur;
		}

		if (!i)
		{
			j = Malloc_SL(SL);
			SL[k].cur = j;
			SL[j].data = e;
			SL[j].cur = 0;
		}
		else
		{
			if (i == SL[MAXSIZE-1].cur)
				SL[MAXSIZE-1].cur = SL[i].cur;
			else
				SL[k].cur = SL[i].cur;
			
			Free_SL(i, SL);
		}
	}
}

int Insert_SL(PNODE SL, int pos, int e)
{
	int i, j, k;

	k = SL[MAXSIZE-1].cur;
	j = 0;
	while (j<pos-2 && k)
	{
		k = SL[k].cur;
		j++;
	}

	if (k && pos>0)
	{
		i = Malloc_SL(SL);
		if (i)
		{
			if (pos == 1)
			{
				SL[i].cur = k;
				SL[MAXSIZE-1].cur = i;
			}
			else
			{
				SL[i].cur = SL[k].cur;
				SL[k].cur = i;
			}
			SL[i].data = e;	

			return 1;
		}
		else
		{
			printf("\nStatic List is full!\n");
			system("pause");
			return 0;
		}
	}
	else
	{
		printf("Element:%d to position:%d,false!\n", e, pos);
		return 0;
	}
}

int LocateElem_SL(int e, PNODE SL)
{
	int i;
	
	i = SL[MAXSIZE-1].cur;
	
	while (i)
	{
		if (SL[i].data == e)
			break;
		
		i = SL[i].cur;
	}
	
	return i;
}

void Traverse_SL(PNODE SL)
{
	int i;

	i = SL[MAXSIZE-1].cur;

	printf("\nTraverse result:\n");
	while (i)
	{
		printf("%d ", SL[i].data);
		i = SL[i].cur;
	}
	printf("\n\n");
}

