/*
	2016��12��16��16:03:00 
*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct Node
{
	int data;
	struct Node * pNext;

}NODE, * PNODE;

PNODE InitList(); //��ʼ��
void TraverseList(PNODE L); //����
void CreatList(PNODE L); //��������
bool ListEmpty(PNODE L); //�ж������Ƿ�Ϊ��
int ListLength(PNODE L); //������
bool SearchMidList(PNODE L, int * pVal); //���������м�ֵ
bool ListInsert(PNODE L, int pos, int val); //����Ԫ��
bool ListDelete(PNODE L, int pos, int * pVal); //ɾ��Ԫ��
bool LocateElem(PNODE L, int pos, int * pVal); //����Ԫ��e����λ�ò�����
bool GetElem(PNODE L, int val, int * pPos); //���������pos��λ��Ԫ���Ƿ���ڲ�������ֵ
void ClearList(PNODE L); //�������

int main(void)
{
	PNODE L;
	int number=1, val, pos;
	
	L = InitList();
	
	printf("��ʼ��L��ListLength(L)=0\n\n");
	printf("1.�鿴����\n");
	printf("2.��������β�巨��\n");
	printf("3.������\n");
	printf("4.�м�ڵ�ֵ\n");
	printf("5.����ڵ�\n");
	printf("6.ɾ���ڵ�\n");
	printf("7.�����ڵ�λ��\n");
	printf("8.�����ڵ�ֵ\n");
	printf("9.�������\n");
	printf("0.�˳�\n");
	printf("��ѡ����Ĳ�����\n");

	while (number != 0)
	{
		scanf("%d", &number);
		switch (number)
		{
		case 1: TraverseList(L); break;
		case 2:	CreatList(L); break;
		case 3: printf("����ĳ����ǣ�%d\n", ListLength(L)); break;
		case 4:	if (SearchMidList(L, &val))
					printf("������м�ֵΪ��%d\n", val);
				else
					printf("����ʧ�ܣ�\n");
				break;

		case 5: printf("������Ҫ������ֵ��λ�ú���ֵ��С���Կո�ָ�����");
				scanf("%d %d", &pos, &val);
				if (ListInsert(L, pos, val))
				{
					printf("Ԫ�ز���ɹ���\n");
					TraverseList(L);
				}
				else
					printf("Ԫ�ز���ʧ�ܣ�\n");
				break;

		case 6: printf("������Ҫɾ����ֵ��λ�ã�");
				scanf("%d", &pos);
				if (ListDelete(L, pos, &val))
				{
					printf("Ԫ��ɾ���ɹ�,ɾ����Ԫ���ǣ�%d��\n", val);
					TraverseList(L);
				}
				else
					printf("Ԫ��ɾ��ʧ�ܣ�\n");
				break;

		case 7: printf("������Ҫ������ֵ��λ�ã�");
				scanf("%d", &pos);
				if (LocateElem(L, pos, &val))
					printf("�ҵ�Ԫ�أ���Ԫ�ص���ֵ�ǣ�%d��\n", val);
				else
					printf("����ʧ�ܣ�\n");
				break;

		case 8: printf("������Ҫ��������ֵ��");
				scanf("%d", &val);
				if (GetElem(L, val, &pos))
					printf("�ҵ�Ԫ�أ���Ԫ�ص�λ���ǣ�%d��\n", pos);
				else
					printf("����ʧ�ܣ�\n");
				break;

		case 9: ClearList(L); break;
		case 0: exit(0);
		default: printf("��������!��������������\n");
		}
		
	}

	system("pause");
	return 0;
}

PNODE InitList() //��ʼ��
{
	PNODE L = (PNODE)malloc(sizeof(NODE));
	L->pNext = NULL;
	return L;
}

void TraverseList(PNODE L) //����
{
	PNODE p = L;

	while ((p=p->pNext))
		printf("%d ", p->data);
	printf("\n");
}

void CreatList(PNODE L) //��������
{
	int n = 20, i;
	PNODE p = L;

	srand((unsigned int)time(0)); //�����������
	for (i=0; i<n; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("��������ڵ�ʧ�ܣ�\n");
			system("pause");
			exit(0);
		}
			p->pNext = pNew;
			pNew->data = rand()%100;
			pNew->pNext = NULL;
			p = pNew;
	}

	printf("\n���崴��L��20�����Ԫ�أ�β�巨����\n");
	TraverseList(L);
}

bool ListEmpty(PNODE L) //�ж������Ƿ�Ϊ��
{
	if (L->pNext)
		return false;
	else
		return true;
}

int ListLength(PNODE L) //������
{
	int i=0;
	PNODE p=L;
	while ((p=p->pNext))
		i++;
	return i;
}

bool SearchMidList(PNODE L, int * pVal) //���������м�ֵ
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

bool ListInsert(PNODE L, int pos, int val) //����Ԫ��
{
	int i=0;
	PNODE p;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));

	if (NULL == pNew)
	{
		printf("��������ڵ�ʧ�ܣ�\n");
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

bool ListDelete(PNODE L, int pos, int * pVal) //ɾ��Ԫ��
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

bool LocateElem(PNODE L, int pos, int * pVal) //���������pos��λ��Ԫ���Ƿ���ڲ�������ֵ
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

bool GetElem(PNODE L, int val, int * pPos) //����Ԫ��val����λ�ò�����
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

void ClearList(PNODE L) //�������
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
