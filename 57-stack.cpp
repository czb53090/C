/*
	2016年12月10日09:56:12
	2016年12月10日10:15:48
	自测时长：19分钟36秒
*/
#include <stdio.h>
#include <stdlib.h>

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

void Init_stack(PSTACK pS);
bool Empty_stack(PSTACK pS);
void Push_stack(PSTACK pS, int val);
bool Pop_stack(PSTACK pS, int * pVal);
void Traverse_stack(PSTACK pS);
void Clear_stack(PSTACK pS);



int main(int argc, char const *argv[])
{
	STACK S;
	int val;
	
	Init_stack(&S);
	Push_stack(&S, 1);
	Push_stack(&S, 2);
	Push_stack(&S, 3);
	Push_stack(&S, 4);
	Push_stack(&S, 5);
	Push_stack(&S, 6);
	Push_stack(&S, 7);
	Traverse_stack(&S);

	if (Pop_stack(&S, &val))
		printf("出栈成功，出栈的元素是%d!.\n", val);
	else
		printf("出栈失败!\n");
	if (Pop_stack(&S, &val))
		printf("出栈成功，出栈的元素是%d!.\n", val);
	else
		printf("出栈失败!\n");
	Traverse_stack(&S);

	printf("清空栈!\n");
	Clear_stack(&S);
	if (Pop_stack(&S, &val))
		printf("出栈成功，出栈的元素是%d!.\n", val);
	else
		printf("出栈失败!\n");
	Traverse_stack(&S);



	
    system("pause");
	return 0;
}

void Init_stack(PSTACK pS)
{
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pBottom)
	{
		printf("分配内存失败!\n");
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

bool Empty_stack(PSTACK pS)
{
	if (pS->pTop->pNext == NULL)
		return true;
	else
		return false;
}

void Push_stack(PSTACK pS, int val)
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
		pNew->data = val;
		pNew->pNext = pS->pTop;
		pS->pTop = pNew;
	}
	return;
}

bool Pop_stack(PSTACK pS, int * pVal)
{
	PNODE r;

	if (Empty_stack(pS))
		return false;
	else
	{
		r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

void Traverse_stack(PSTACK pS)
{
	PNODE p = pS->pTop;

	while(p->pNext)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

void Clear_stack(PSTACK pS)
{
	PNODE p1, p2;

	if (Empty_stack(pS))
		return;
	else
	{
		p1 = pS->pTop;
		while (p1->pNext)
		{
			p2 = p1->pNext;
			free(p1);
			p1 = p2;
		}
		pS->pTop = pS->pBottom;
		p1 = p2 = NULL;
	}
}