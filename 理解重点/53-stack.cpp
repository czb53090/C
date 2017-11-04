/*
	2016��12��9��14:38:14
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK pS);
bool Is_empty(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
bool pop(PSTACK pS, int * pVal);
void clear(PSTACK pS);


int main(void)
{
	STACK S;
	int val;

	init(&S);
	push(&S, 1);
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	traverse(&S);
	if(pop(&S, &val))
	{
		printf("��ջ�ɹ�����ջ����ֵ��:%d\n", val);
	}
	else
		printf("��ջʧ��!\n");
	traverse(&S);

	printf("���ջ!\n");
	clear(&S);
	traverse(&S);

	if(pop(&S, &val)) //��һ����Ϊ����֤ջ�Ƿ�����Ѿ����
	{
		printf("��ջ�ɹ�����ջ����ֵ��:%d\n", val);
	}
	else
		printf("��ջʧ��!\n");

	system("pause");
	return 0;
}

void init(PSTACK pS)
{
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pBottom)
	{
		printf("��̬�����ڴ�ʧ��!\n");
		system("pause");
		exit(0);
	}
	else
	{
		pS->pTop = pS->pBottom;
		pS->pTop->pNext = NULL;
	}
	return;
}

bool Is_empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("��̬�����ڴ�ʧ��!\n");
		system("pause");
		exit(0);
	}
	else
	{
		pNew->data = val;
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
	}
	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p->pNext)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool pop(PSTACK pS, int * pVal)
{
	PNODE p;
	if (Is_empty(pS))
		return false;
	else
	{
		p = pS->pTop;
		*pVal = p->data;
		pS->pTop = p->pNext;
		free(p);
		p = NULL;
	}
	return true;
}

void clear(PSTACK pS)
{
	PNODE p1, p2;
	p1 = p2 = NULL;

	if (Is_empty(pS))
		return;
	else
	{
		p1 = pS->pTop;
		while (p1 != pS->pBottom)
		{
			p2 = p1->pNext;
			free(p1);
			p1 = p2;
		}
		p1 = p2 = NULL;
		pS->pTop = pS->pBottom;
	}
}
