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

PNODE Init();
void Cread_Poker_list(PNODE pHead);
void Traverse_list(PNODE pHead);
void Clear_list(PNODE pHead);

int main(int argc, char const *argv[])
{
	PNODE p;

	p = Init();
	Cread_Poker_list(p);
	Traverse_list(p);

	Clear_list(p);

    system("pause");
	return 0;
}

PNODE Init()
{
	PNODE p, pTail;
	int i;

	for (i=0; i<13; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配内存失败!\n");
			system("pause");
			exit(0);
		}
		else
		{
			if (i == 0)
			{
				p = pTail = pNew;
				pNew->data = 0;
				continue;
			}
			pNew->data = 0;
			pTail->pNext = pNew;
			pTail = pNew;
			}
	}
	pTail->pNext = p;
	
	return p;
}

void Cread_Poker_list(PNODE pHead)
{
	PNODE p;
	int count = 2, i;

	p = pHead;
	p->data = 1;

	while (1)
	{
		for (i=0; i<count; i++)
		{
			p = p->pNext;
			if (p->data != 0)
				i--;
		}
		if (p->data == 0)
		{
			p->data = count;
			count++;
			if (count == 14)
			break;
		}
	}
}

void Traverse_list(PNODE pHead)
{
	PNODE p, pTail;
	p = pTail = pHead;

	while(pTail->pNext != p)
	{
		printf("%d  ", pTail->data);
		pTail = pTail->pNext;
	}
	printf("%d\n", pTail->data);
}

void Clear_list(PNODE pHead)
{
	PNODE p1, p2;

	if (pHead->pNext)
		return;
	else
	{
		p1 = pHead;
		while(p1)
		{
			p2 = p1->pNext;
			free(p1);
			p1 = p2;
		}
		pHead->pNext = NULL;
	}
}