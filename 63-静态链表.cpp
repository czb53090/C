/*
	2016年12月15日15:18:16
*/

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
bool ListInsert(StaticLinkList L, int pos, int val);
int ListLength(StaticLinkList L);
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
	printf("链表的长度是：%d\n", ListLength(L));

	printf("请输入你要插入数值的位置和数值大小：");
	scanf("%d %d", &pos, &val);
	ListInsert(L, pos, val);
	TraverseList(L);

	printf("请输入你要删除数值的位置：");
	scanf("%d", &pos);
	if (ListDelete(L, pos, &val))
		printf("删除成功，删除的元素是：%d\n", val);
	else
		printf("删除失败!\n");
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

	printf("请输入你想要输入元素的长度：len = _____\b\b\b\b\b");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("请输入第%d个节点的数值：_____\b\b\b\b\b", i);
		scanf("%d", &val);
		
		L[i].data = val;
	}
	L[i-1].cur = 0;
	L[0].cur = i;
	L[MAXSIZE-1].cur = 1;
}

int Malloc_SLL(StaticLinkList L)
{
	int i = L[0].cur;

	if (L[i].cur)
		L[0].cur = L[i].cur;
	return i;
}

bool ListInsert(StaticLinkList L, int pos, int val)
{
	int i, k, j;

	if (pos<1 || pos>ListLength(L)+1)
		return false;

	k = MAXSIZE-1;
	j = Malloc_SLL(L); //找到备用链表中第一个空闲位置的下标

	if (j)
	{
		L[j].data = val;

		for (i=0; i<pos-1; i++)
			k = L[k].cur; //找到第pos-1个位置的下标
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return true;
	}
	return false;
}

int ListLength(StaticLinkList L)
{
	int i, j=0;

	for (i=L[MAXSIZE-1].cur; i; i=L[i].cur)
		j++;
	return j;
}

bool ListDelete(StaticLinkList L, int pos, int * pVal)
{
	int i, k;

	if (pos<1 || pos>ListLength(L))
		return false;

	k = MAXSIZE-1;
	for (i=0; i<pos-1; i++)
		k = L[k].cur;
	
	// 把第pos-1（即下标为k）个位置的元素链接到第pos+1（即i+1）个的位置
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

/*在Vc++6.0中的输出结果是：
--------------------------
请输入你想要输入元素的长度：len = 7____
请输入第1个节点的数值：1____
请输入第2个节点的数值：22___
请输入第3个节点的数值：2____
请输入第4个节点的数值：33___
请输入第5个节点的数值：44___
请输入第6个节点的数值：55___
请输入第7个节点的数值：666__
1 22 2 33 44 55 666
链表的长度是：7
请输入你要插入数值的位置和数值大小：8 6666
1 22 2 33 44 55 666 6666
请输入你要删除数值的位置：3
删除成功，删除的元素是：2
1 22 33 44 55 666 6666
--------------------------
*/