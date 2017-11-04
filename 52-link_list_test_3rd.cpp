/*
	2016年12月8日21:15:00
	一小时完成该链表
*/

# include <stdio.h>
# include <stdlib.h>
# include "52-link_list_test_3rd.h"

// typedef struct Node
// {
// 	int data;
// 	struct Node * pNext;
// }NODE, * PNODE;

// PNODE Create_list(void);
// bool Is_empty(PNODE pHead);
// void Traverse_list(PNODE pHead);
// int Length_list(PNODE pHead);
// bool Insert_list(PNODE pHead, int pos, int val);
// bool Delete_list(PNODE pHead, int pos, int * pVal);
// void Sort_list(PNODE pHead);
// bool Search_list(PNODE pHead, int val);


int main(void)
{
	PNODE pHead;
	int val;
	int pos, number;

	pHead = Create_list();
	if(Is_empty(pHead))
		printf("链表为空!\n");
	else
		Traverse_list(pHead);
	printf("链表的长度为：%d\n", Length_list(pHead));

	printf("请输入你所要插入的数值：");
	scanf("%d", &number);
	printf("请输入你要插入数值的位置：");
	scanf("%d", &pos);
	if (Insert_list(pHead, pos, number))
	{
		printf("插入数值成功!\n");
		Traverse_list(pHead);
	}
	else
		printf("插入数值失败!\n");

	printf("请输入你要查找的数值：");
	scanf("%d", &number);
	if(Search_list(pHead, number))
		printf("找到该数值!\n");
	else
		printf("未找到该数值!\n");

	printf("请输入你所要删除元素的位置：");
	scanf("%d", &pos);
	if (Delete_list(pHead, pos, &val))
	{
		printf("删除数值成功,您删除的数值是%d\n", val);
		Traverse_list(pHead);
	}
	else
		printf("删除数值失败!\n");

	printf("自动排序（由小到大）:\n");
	if(Is_empty(pHead))
		printf("链表为空,排序失败!\n");
	else
	{
		Sort_list(pHead);
		printf("排序成功!\n");
		Traverse_list(pHead);
	}

	system("pause");
	return 0;
}

PNODE Create_list(void)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE)), p;
	int len, i, val;

	printf("请输入您想要创建的链表的长度：len = ");
	scanf("%d", &len);
	if (len < 1)
	{
		printf("输入数值有误，创建链表失败!\n");
		system("pause");
		exit(0);
	}

	p = pHead;
	p->pNext = NULL;
	for (i=0; i<len; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("创建链表失败!\n");
			system("pause");
			exit(0);
		}
		printf("请输入第%d个节点的数值:", i+1);
		scanf("%d", &val);
		pNew->data = val;
		p->pNext = pNew;
		pNew->pNext = NULL;
		p = pNew;
	}
	return pHead;
}

bool Is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}

void Traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

int Length_list(PNODE pHead)
{
	int len;
	PNODE p = pHead->pNext;

	for (len=0; p; len++,p=p->pNext);
	
	return len;
}

bool Insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("创建链表失败!\n");
		system("pause");
		exit(0);
	}

	while(p && i<pos-1)
	{
		p = p->pNext;
		i++; //循环之后i应该等于pos-1
	}
	if (i>pos-1 || p==NULL)
		return false;

	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

bool Delete_list(PNODE pHead, int pos, int * pVal)
{
	PNODE p1=pHead, p2;
	int i = 0;

	while(p1->pNext && i<pos-1)
	{
		p1 = p1->pNext;
		i++;
	}
	if (i>pos-1 || NULL==p1->pNext)
		return false;
	p2 = p1->pNext;
	*pVal = p2->data;
	p1->pNext = p2->pNext;
	free(p2);
	p2 = NULL;
	return true;
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
}

bool Search_list(PNODE pHead, int val)
{
	PNODE p = pHead;
	while(p)
	{
		if (val == p->data)
		{
			return true;
			break;
		}
		p = p->pNext;
	}
	if (p == NULL)
		return false;
}
