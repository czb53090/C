/*
	2016��12��8��21:15:00
	һСʱ��ɸ�����
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
		printf("����Ϊ��!\n");
	else
		Traverse_list(pHead);
	printf("����ĳ���Ϊ��%d\n", Length_list(pHead));

	printf("����������Ҫ�������ֵ��");
	scanf("%d", &number);
	printf("��������Ҫ������ֵ��λ�ã�");
	scanf("%d", &pos);
	if (Insert_list(pHead, pos, number))
	{
		printf("������ֵ�ɹ�!\n");
		Traverse_list(pHead);
	}
	else
		printf("������ֵʧ��!\n");

	printf("��������Ҫ���ҵ���ֵ��");
	scanf("%d", &number);
	if(Search_list(pHead, number))
		printf("�ҵ�����ֵ!\n");
	else
		printf("δ�ҵ�����ֵ!\n");

	printf("����������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d", &pos);
	if (Delete_list(pHead, pos, &val))
	{
		printf("ɾ����ֵ�ɹ�,��ɾ������ֵ��%d\n", val);
		Traverse_list(pHead);
	}
	else
		printf("ɾ����ֵʧ��!\n");

	printf("�Զ�������С����:\n");
	if(Is_empty(pHead))
		printf("����Ϊ��,����ʧ��!\n");
	else
	{
		Sort_list(pHead);
		printf("����ɹ�!\n");
		Traverse_list(pHead);
	}

	system("pause");
	return 0;
}

PNODE Create_list(void)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE)), p;
	int len, i, val;

	printf("����������Ҫ����������ĳ��ȣ�len = ");
	scanf("%d", &len);
	if (len < 1)
	{
		printf("������ֵ���󣬴�������ʧ��!\n");
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
			printf("��������ʧ��!\n");
			system("pause");
			exit(0);
		}
		printf("�������%d���ڵ����ֵ:", i+1);
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
		printf("��������ʧ��!\n");
		system("pause");
		exit(0);
	}

	while(p && i<pos-1)
	{
		p = p->pNext;
		i++; //ѭ��֮��iӦ�õ���pos-1
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
