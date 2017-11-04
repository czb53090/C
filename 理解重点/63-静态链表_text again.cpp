# include <stdio.h>
# include <stdlib.h>
# define MAXSIZE 1000

typedef struct Node
{
	int data;
	int cur;
} StaticLinkList[MAXSIZE];

void InitList(StaticLinkList L);
void CreatList(StaticLinkList L);
int Malloc_SLL(StaticLinkList L);
int ListLength(StaticLinkList L);
bool ListInsert(StaticLinkList L, int pos, int val);
bool ListDelete(StaticLinkList L, int pos, int * pVal);
void Free_SLL(StaticLinkList L, int k);
void TraverseList(StaticLinkList L);


int main(void)
{
	StaticLinkList L;
	int pos, val;

	InitList(L);
	CreatList(L);
	TraverseList(L);
	printf("静态链表的长度是：%d\n", ListLength(L));

	printf("请输入你要插入数值的位置和数值大小：");
	scanf("%d %d", &pos, &val);
	if (ListInsert(L, pos, val))
		printf("元素插入成功!\n");
	else
		printf("元素插入失败!\n");
	TraverseList(L);

	printf("请输入你要删除数值的位置：");
	scanf("%d", &pos);
	if(ListDelete(L, pos, &val))
		printf("元素删除成功，删除的元素是：%d\n", val);
	else
		printf("元素删除失败!\n");
	TraverseList(L);

	system("pause");
	return 0;
}

void InitList(StaticLinkList L)
{
	int i;

	for (i=0; i<MAXSIZE-1; i++)
		L[i].cur = i+1;
	L[MAXSIZE-1].cur = 0;
}

void CreatList(StaticLinkList L)
{
	int i, n, val;

	printf("请输入你要创建静态链表的长度：len = ");
	scanf("%d", &n);

	for (i=1; i<=n; i++)
	{
		printf("请输入第%d个节点的数值：", i);
		scanf("%d", &val);
		L[i].data = val;
	}
	L[0].cur = i;
	L[MAXSIZE-1].cur = 1;
	L[i-1].cur = 0;
}

int Malloc_SLL(StaticLinkList L)
{
	int i = L[0].cur;

	if (L[i].cur)
		L[0].cur = L[i].cur;

	return i;
}

int ListLength(StaticLinkList L)
{
	int i, j;

	for (i=L[MAXSIZE-1].cur,j=0; i; i=L[i].cur)
		j++;
	return j;
}

bool ListInsert(StaticLinkList L, int pos, int val)
{
	int i, k, j;

	if (pos<1 || pos>ListLength(L)+1)
		return false;

	j = Malloc_SLL(L);
	k = MAXSIZE-1;
	if (j)
	{
		L[j].data = val;
		for (i=0; i<pos-1; i++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return true;
	}
	return false;
}

bool ListDelete(StaticLinkList L, int pos, int * pVal)
{
	int i, k;
	
	if (pos<1 || pos>ListLength(L))
		return false;
	
	k = MAXSIZE-1;
	for (i=0; i<pos-1; i++)
		k = L[k].cur;

	i = L[k].cur;
	L[k].cur = L[i].cur;

	*pVal = L[i].data;

	Free_SLL(L, i);
	return true;
}

void Free_SLL(StaticLinkList L, int k)
{
	L[k].cur = L[0].cur;
	L[0].cur = k;
}

void TraverseList(StaticLinkList L)
{
	int i;

	for (i=L[MAXSIZE-1].cur; i; i=L[i].cur)
		printf("%d ", L[i].data);
	printf("\n");
}