/*
	2016��12��15��15:18:16
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
	printf("����ĳ����ǣ�%d\n", ListLength(L));

	printf("��������Ҫ������ֵ��λ�ú���ֵ��С��");
	scanf("%d %d", &pos, &val);
	ListInsert(L, pos, val);
	TraverseList(L);

	printf("��������Ҫɾ����ֵ��λ�ã�");
	scanf("%d", &pos);
	if (ListDelete(L, pos, &val))
		printf("ɾ���ɹ���ɾ����Ԫ���ǣ�%d\n", val);
	else
		printf("ɾ��ʧ��!\n");
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

	printf("����������Ҫ����Ԫ�صĳ��ȣ�len = _____\b\b\b\b\b");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("�������%d���ڵ����ֵ��_____\b\b\b\b\b", i);
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
	j = Malloc_SLL(L); //�ҵ����������е�һ������λ�õ��±�

	if (j)
	{
		L[j].data = val;

		for (i=0; i<pos-1; i++)
			k = L[k].cur; //�ҵ���pos-1��λ�õ��±�
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
	
	// �ѵ�pos-1�����±�Ϊk����λ�õ�Ԫ�����ӵ���pos+1����i+1������λ��
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

/*��Vc++6.0�е��������ǣ�
--------------------------
����������Ҫ����Ԫ�صĳ��ȣ�len = 7____
�������1���ڵ����ֵ��1____
�������2���ڵ����ֵ��22___
�������3���ڵ����ֵ��2____
�������4���ڵ����ֵ��33___
�������5���ڵ����ֵ��44___
�������6���ڵ����ֵ��55___
�������7���ڵ����ֵ��666__
1 22 2 33 44 55 666
����ĳ����ǣ�7
��������Ҫ������ֵ��λ�ú���ֵ��С��8 6666
1 22 2 33 44 55 666 6666
��������Ҫɾ����ֵ��λ�ã�3
ɾ���ɹ���ɾ����Ԫ���ǣ�2
1 22 33 44 55 666 6666
--------------------------
*/