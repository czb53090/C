/*
	2016年12月10日10:19:40
	2016年12月10日11:16:45
	自测时长：57分钟5秒
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

PNODE Cread_list();
void Traverse_list(PNODE pHead);
bool Is_empty(PNODE pHead);
bool Insert_list(PNODE pHead, int pos, int val);
bool Delete_list(PNODE pHead, int pos, int * pVal);
bool Search_list(PNODE pHead, int pos, int * pVal);
void Sort_list(PNODE pHead);
void Clear_list(PNODE pHead);

int main(int argc, char const *argv[])
{
	PNODE p;
	int pos, val;

	p = Cread_list();
	Traverse_list(p);

	printf("请输入你要插入数值的位置：");
	scanf("%d", &pos);
	printf("请输入你要插的入数值：");
	scanf("%d", &val);
	if(Insert_list(p, pos, val))
		printf("插入数值成功!\n");
	else
		printf("插入数值失败!\n");
	Traverse_list(p);

	printf("请输入你要删除数值的位置：");
	scanf("%d", &pos);
	
	if (Is_empty(p))
		printf("链表为空，删除失败");
	else
	{
		if(Delete_list(p, pos, &val))
			printf("已删除，该值为%d\n", val);
		else
			printf("未找到，删除失败!\n");
	}
	Traverse_list(p);
	
	printf("请输入你要搜索数值的位置：");
	scanf("%d", &pos);
	
	if (Is_empty(p))
		printf("链表为空，查找失败");
	else
	{
		if(Search_list(p, pos, &val))
			printf("找到，该值为%d\n", val);
		else
			printf("未找到该位置\n");
	}
	Traverse_list(p);

	printf("排序（由小到大）：\n");
	Sort_list(p);
	Traverse_list(p);

	printf("清空链表!\n");
	Clear_list(p);
	Traverse_list(p);

    system("pause");
	return 0;
}

PNODE Cread_list()
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE)), pTail;
	int len, flag=1, i, val;
	
	if (NULL == pHead)
	{
		printf("分配内存失败!\n");
		system("pause");
		exit(0);
	}
	else
	{
		printf("请输入您要创建链表的长度：len = ");
		while (flag)
		{
			scanf("%d", &len);
			if (len < 1)
			{
				printf("长度输入有误，请重新输入!\n");
				continue;
			}
			flag = 0;
		}
		pTail = pHead;
		for (i=0; i<len; i++)
		{
			PNODE pNew = (PNODE)malloc(sizeof(NODE));
			if (NULL == pHead)
			{
				printf("分配内存失败!\n");
				system("pause");
				exit(0);
			}
			else
			{
				printf("请输入第%d个节点的数值：", i+1);
				scanf("%d", &val);
				pNew->data = val;
				pTail->pNext = pNew;
				pNew->pNext = NULL;
				pTail = pNew;
			}
		}
	}



	return pHead;
}

void Traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while(p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool Is_empty(PNODE pHead)
{
	if (pHead->pNext)
		return false;
	else
		return true;
}

bool Insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配内存失败!\n");
		system("pause");
		exit(0);
	}
	else
	{
		p = pHead;
		while (i<pos-1 && p)
		{
			i++;
			p = p->pNext;
		}
		if(i>pos-1 || p==NULL)
			return false;
		else
		{
			pNew->data = val;
			pNew->pNext = p->pNext;
			p->pNext = pNew;
		}
		return true;
	}
}

bool Delete_list(PNODE pHead, int pos, int * pVal)
{
	PNODE p1, p2;
	int i = 0;

	
	p1 = pHead;
	while (i<pos-1 && p1->pNext)
	{
		i++;
		p1 = p1->pNext;
	}
	if(i>pos-1 || p1->pNext==NULL)
		return false;
	else
	{
		p2 = p1->pNext;
		*pVal = p2->data;
		p1->pNext = p2->pNext;
		free(p2);
		p2 = NULL;
		return true;
	}
	
}
bool Search_list(PNODE pHead, int pos, int * pVal)
{
	PNODE p;
	int i = 0;
	
	p = pHead;
	while (i<pos-1 && p->pNext)
	{
		i++;
		p = p->pNext;
	}
	if(i>pos-1 || p->pNext==NULL)
		return false;
	else
	{
		*pVal = p->pNext->data;
		return true;
	}
	
}

void Sort_list(PNODE pHead)
{
	PNODE p1, p2;
	int temp;

	for (p1=pHead->pNext; p1->pNext; p1=p1->pNext)
		for (p2=p1->pNext; p2; p2=p2->pNext)
			if (p1->data > p2->data)
			{
				temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
	return;
}
void Clear_list(PNODE pHead)
{
	PNODE p1, p2;

	if (Is_empty(pHead))
		return;
	else
	{
		p1 = pHead->pNext;
		while(p1)
		{
			p2 = p1->pNext;
			free(p1);
			p1 = p2;
		}
		pHead->pNext = NULL;
	}
}