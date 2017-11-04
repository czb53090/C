/*
	2016年12月16日16:03:00 
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, * PNODE;

PNODE InitList(); //初始化
void TraverseList(PNODE L); //遍历
void CreatList(PNODE L); //创建链表
bool ListEmpty(PNODE L); //判断链表是否为空
int ListLength(PNODE L); //链表长度
bool SearchMidList(PNODE L, int * pVal); //查找链表中间值
bool ListInsert(PNODE L, int pos, int val); //插入元素
bool ListDelete(PNODE L, int pos, int * pVal); //删除元素
bool LocateElem(PNODE L, int pos, int * pVal); //查找元素e所在位置并返回
bool GetElem(PNODE L, int val, int * pPos); //查找链表第pos个位置元素是否存在并返回其值
void ClearList(PNODE L); //清空链表

int main(void)
{
	PNODE L;
	int number=1, val, pos;
	
	L = InitList();
	
	printf("初始化L后：ListLength(L)=0\n\n");
	printf("1.查看链表\n");
	printf("2.创建链表（尾插法）\n");
	printf("3.链表长度\n");
	printf("4.中间节点值\n");
	printf("5.插入节点\n");
	printf("6.删除节点\n");
	printf("7.搜索节点位置\n");
	printf("8.搜索节点值\n");
	printf("9.清空链表\n");
	printf("0.退出\n");
	printf("请选择你的操作：\n");

	while (number != 0)
	{
		scanf("%d", &number);
		switch (number)
		{
		case 1: TraverseList(L); break;
		case 2:	CreatList(L); break;
		case 3: printf("链表的长度是：%d\n", ListLength(L)); break;
		case 4:	if (SearchMidList(L, &val))
					printf("链表的中间值为：%d\n", val);
				else
					printf("查找失败！\n");
				break;

		case 5: printf("请输入要插入数值的位置和数值大小（以空格分隔）：");
				scanf("%d %d", &pos, &val);
				if (ListInsert(L, pos, val))
				{
					printf("元素插入成功！\n");
					TraverseList(L);
				}
				else
					printf("元素插入失败！\n");
				break;

		case 6: printf("请输入要删除数值的位置：");
				scanf("%d", &pos);
				if (ListDelete(L, pos, &val))
				{
					printf("元素删除成功,删除的元素是：%d！\n", val);
					TraverseList(L);
				}
				else
					printf("元素删除失败！\n");
				break;

		case 7: printf("请输入要搜索数值的位置：");
				scanf("%d", &pos);
				if (LocateElem(L, pos, &val))
					printf("找到元素，该元素的数值是：%d！\n", val);
				else
					printf("查找失败！\n");
				break;

		case 8: printf("请输入要搜索的数值：");
				scanf("%d", &val);
				if (GetElem(L, val, &pos))
					printf("找到元素，该元素的位置是：%d！\n", pos);
				else
					printf("查找失败！\n");
				break;

		case 9: ClearList(L); break;
		case 0: exit(0);
		default: printf("输入有误!请重新输入操作项：\n");
		}
		
	}

	system("pause");
	return 0;
}

PNODE InitList() //初始化
{
	PNODE L = (PNODE)malloc(sizeof(NODE));
	L->pNext = NULL;
	return L;
}

void TraverseList(PNODE L) //遍历
{
	PNODE p = L;

	while ((p=p->pNext))
		printf("%d ", p->data);
	printf("\n");
}

void CreatList(PNODE L) //创建链表
{
	int n = 20, i;
	PNODE p = L;

	srand((unsigned int)time(0)); //置随机数种子
	for (i=0; i<n; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("创建链表节点失败！\n");
			system("pause");
			exit(0);
		}
			p->pNext = pNew;
			pNew->data = rand()%100;
			pNew->pNext = NULL;
			p = pNew;
	}

	printf("\n整体创建L的20个随机元素（尾插法）：\n");
	TraverseList(L);
}

bool ListEmpty(PNODE L) //判断链表是否为空
{
	if (L->pNext)
		return false;
	else
		return true;
}

int ListLength(PNODE L) //链表长度
{
	int i=0;
	PNODE p=L;
	while ((p=p->pNext))
		i++;
	return i;
}

bool SearchMidList(PNODE L, int * pVal) //查找链表中间值
{
	PNODE Slow, Fast;

	Slow = Fast = L;

	if (ListEmpty(L))
		return false;
	else
	{
		while (Fast->pNext!=NULL)
		{
			if (Fast->pNext->pNext != NULL)
			{
				Fast = Fast->pNext->pNext;
				Slow = Slow->pNext;
			}
			else
				Fast = Fast->pNext;
		}
		*pVal = Slow->data;
		return true;
	}
}

bool ListInsert(PNODE L, int pos, int val) //插入元素
{
	int i=0;
	PNODE p;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));

	if (NULL == pNew)
	{
		printf("创建链表节点失败！\n");
		system("pause");
		exit(0);
	}

	p = L;
	while (i<pos-1 && p)
	{
		i++;
		p = p->pNext;
	}
	if (i>pos-1 || p==NULL)
		return false;
	else
	{
		pNew->data = val;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		return true;
	}
}

bool ListDelete(PNODE L, int pos, int * pVal) //删除元素
{
	int i=0;
	PNODE p = L, p2;

	if (ListEmpty(L))
		return false;
	else
	{
		while (i<pos-1 && p->pNext)
		{
			i++;
			p = p->pNext;
		}
		if (i>pos-1 || !p->pNext)
			return false;
		else
		{
			p2 = p->pNext;
			*pVal = p2->data;
			p->pNext = p2->pNext;
			free(p2);
			p2 = NULL;
			return true;
		}
	}
}

bool LocateElem(PNODE L, int pos, int * pVal) //查找链表第pos个位置元素是否存在并返回其值
{
	int i=0;
	PNODE p = L;

	while (i<pos && p)
	{
		i++;
		p = p->pNext;
	}
	if (i>pos || p==NULL)
		return false;
	else
		*pVal = p->data;
	return true;
}

bool GetElem(PNODE L, int val, int * pPos) //查找元素val所在位置并返回
{
	int i=0;
	PNODE p = L;

	while (i<ListLength(L))
	{
		i++;
		p=p->pNext;
		if (val == p->data)
			break;
	}
	if (i>ListLength(L) || p==NULL)	
		return false;
	else
		*pPos = i;
	return true;
}

void ClearList(PNODE L) //清空链表
{
	PNODE p1=L->pNext, p2;

	while (p1)
	{
		p2 = p1->pNext;
		free(p1);
		p1 = p2;
	}
	p1 = p2 = NULL;
	L->pNext = NULL;
}
