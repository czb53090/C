/*	
	2016��11��8��13:03:59

ʵ��Ŀ�ģ�����һ����ѭ��������
���裺
	1.����������main������
		����main��������һ�����ͷ����ַ�ı���pHeadΪNULL
		�ð�Create_List���ص�ָ���������pHead
		�ٵ���Create_List��������е���ֵ

	2.����������Create_List������
		����һ���������Ч���ݵ�ͷ���pHead���ж����Ƿ�ΪNULL
		����һ�����β����ַ�ı���pTail
		�ȶ���val=0������ѭ������valΪ1����ѭ��
		��ѭ��������nΪ2����û�д�������ֱ�ӽ�������
		ÿ��ѭ������һ���½ڵ�pNew
		�ж�pNewָ������Ƿ�ΪNULL
		������Ҫ�����������ֵval
		��pNew->data = val��Ȼ��pTail->pNextָ��pNew
		����pNew->pNext = NULL�������pTailָ��pNew

	3.���������Traverse_List�����У�
		����һ��struct Node * pָ��pHead->pNext
		��ѭ������p������NULL��ÿ�����data��ָ����һ���ڵ�
		���ʵ�����������۹�������֤�Ķ���������

	4.������������ҵ���ʾ�У������ޣ�
		����һ��struct Node * pָ��pHead
		���û�������Ҫ��������ֵ
		��forѭ��������Ϊp��ΪNULL
		ÿ��ѭ���ж�p->data == val���ü�������n++
		ѭ����������pָ��p->pNext
		�����������

	5.�������ڵ�
		���û�������Ҫ���Ǹ���ֵval������ֵ����Ҫ�������ֵnumber
		��forѭ������ʼ��struct Node * p���ڲ���pHead������Ϊp!=NULL
		ÿ��ѭ�����·���һ���ռ�pNew���ж�p->data�Ȳ�����val
		�����ȣ�����pNew->pNext= p->pNext;   p->pNext = pNew;
		pNew->data = number; p=p->pNext; n++;  nΪ��������
		ѭ��֮������pָ����һ��
		���������������(n!=0)�����ϲ�����Ѿ���ɣ�ֻ��������
		�����������������(n == 0)���ٴ����û�������ֵ���ٴ��ظ����ϲ���
		
	6.����ɾ��ָ���ڵ�
		���û�������Ҫɾ���Ľڵ����Ӧ����ֵval
		����struct Node * p = pHead; struct Node * pTail = p->pNext;
		��forѭ����ÿ������ΪpTail��ΪNULL���ж�val�Ȳ�����pTail->data
		�����ȣ���p->pNext = pTail->pNext; �ͷ�pTail�Ŀռ�
		���������pָ����һ�� �� ��������������

	7.�ͷ�����ռ䣨ɾ������
		����һ��struct Node * p�ṹ��pָ��pHead
		��forѭ��������ΪpHead��ΪNULL
		ÿ��ѭ����pָ��p->pNext,�ٰ�pHead�Ŀռ��ͷŵ�
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

struct Node
{
	int data;
	struct Node * pNext;
};

struct Node * Create_List(void);
void Traverse_List(struct Node * pHead); 
void Search_List(struct Node * pHead);
void Insert_List(struct Node * pHead);
void Delete_List(struct Node * pHead);
void Clear_List(struct Node * pHead);

int main(void)
{
	struct Node * pHead = NULL;
	
	pHead = Create_List(); //��������
	Traverse_List(pHead);  //����������������
	Search_List(pHead);    //���������������ָ����ֵ�Ľڵ��Ƿ���ڣ�	
	Insert_List(pHead);    //����Ĳ��루��ָ����ֵ֮������½ڵ㣩
	Delete_List(pHead);    //�����ɾ����ɾ��ָ����ֵ�Ľڵ㣩	
	Clear_List(pHead);     //�����������ͷſռ䣩

	system("pause");
	return 0;
}

struct Node * Create_List(void) //��������
{
	int i=1, val=0;
	
	struct Node * pHead = (struct Node *)malloc(sizeof(struct Node)); //����һ���յ�ͷ���
	struct Node * pTail = pHead;
	if (pHead == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}

	printf("(ע�⣺���������� [-32768 ~ 32767]���������� -1 ��������)\n");
	while (val != -1)
	{
		struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
		if (pNew == NULL)
		{
			printf("����ռ�ʧ�ܣ�\n");
			exit(-1);
		}

		printf("�����%d���ڵ����ֵ(����)��", i);
		scanf("%d", &val);

		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
		++i;
	}
	if(i == 2)
	{
		printf("��������ʧ��\n");
		exit(-1);
	}
	return pHead;
}

void Traverse_List(struct Node * pHead) //����������������
{
	struct Node * p = pHead->pNext;
	int cnt=0, i;
	printf("�����и����ڵ����ֵΪ��\n");
	for (i=1; NULL != p; ++i)
	{
		if(p->data == -1) //��dataΪ-1��������ֵ
			break;
		if(i<10) //Ϊ��ʹ������������
			printf("[%d]:%-10d", i, p->data);
		else if (i<100)
			printf("[%d]:%-9d", i, p->data);
		else
			printf("[%d]:%-8d", i, p->data);
		p = p->pNext;
		
		// ����
		++cnt;
		if(0==cnt%5 && cnt!=0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

void Search_List(struct Node * pHead) //���������������ָ����ֵ�Ľڵ��Ƿ���ڣ�
{
	struct Node * p;
	int val, n=0, i;
	printf("\n������Ҫ��������ֵ��");
	scanf("%d", &val);

	for(p=pHead,i=0; p; p=p->pNext,++i)//��pHead==NULLֹͣѭ��
		if(p->data == val)
		{
			n++;
			printf("[%d]  ", i);
		}

	if (n != 0)
		printf("λ���Ϲ��ҵ�%d�����ϵ���ֵ��\n", n);
	else
		printf("û���ҵ�����ֵ��\n");
}

void Insert_List(struct Node * pHead) //����Ĳ��루��ָ����ֵ֮������½ڵ㣩
{
	int val, n=0, number;
	struct Node * p;
	
	printf("\n������Ҫ���ĸ���ֵ֮�������ֵ��");
	scanf("%d", &val);
	printf("��������Ҫ�������ֵ��");
	scanf("%d", &number);
	for(p=pHead; p; p=p->pNext)
	{
		struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
		if(p->data == val)
		{
			pNew->pNext = p->pNext;
			p->pNext = pNew;
			pNew->data = number;
			p = p->pNext;
			n++;
		}
	}
	
	while(n == 0)
	{
		printf("δ�ҵ�������������ֵ�����ٴ����룺");
		scanf("%d", &val);
		for(p=pHead; p; p=p->pNext)
		{
			struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
			if (pNew == NULL)
			{
				printf("����ռ�ʧ�ܣ�\n");
				exit(-1);
			}
			if(p->data == val)
			{
				pNew->pNext= p->pNext;
				p->pNext = pNew;
				pNew->data = number;
				n++;
			}
		}
	}
	if(n != 0)
	{
		printf("\n���ҵ�%d�������������ֵ,�Ѳ���������\n", n);
		Traverse_List(pHead);
	}
}

void Delete_List(struct Node * pHead) //�����ɾ����ɾ��ָ����ֵ�Ľڵ㣩
{
	int val;
	struct Node * p;
	struct Node * pTail;

	printf("\n������Ҫɾ������ֵ��");
	scanf("%d", &val);
	
	for(p = pHead,pTail=p->pNext; pTail; pTail=p->pNext)
	{
		if (val==pTail->data) //�����ɹ�������pָ����һ��
		{
			p->pNext = pTail->pNext;
			free(pTail);
		}
		else
			p=p->pNext;

	}

	Traverse_List(pHead);
}

void Clear_List(struct Node * pHead) //�����������ͷſռ䣩
{
	struct Node * p;
	while(NULL != pHead)
	{
		p = pHead->pNext;
		free(pHead);
		pHead = p;
	}
}

/*��Vc++6.0�е��������ǣ�
--------------------------
�����1���ڵ����ֵ(����)��1
�����2���ڵ����ֵ(����)��2
�����3���ڵ����ֵ(����)��3
�����4���ڵ����ֵ(����)��3
�����5���ڵ����ֵ(����)��4
�����6���ڵ����ֵ(����)��4
�����7���ڵ����ֵ(����)��5
�����8���ڵ����ֵ(����)��2
�����9���ڵ����ֵ(����)��31
�����10���ڵ����ֵ(����)��123
�����11���ڵ����ֵ(����)��433
�����12���ڵ����ֵ(����)��2
�����13���ڵ����ֵ(����)��-1
�����и����ڵ����ֵΪ��
1       2       3       3       4
4       5       2       31      123
433     2

������Ҫ��������ֵ��3
���ҵ�2��������ֵ��
  
������Ҫ���ĸ���ֵ֮�������ֵ��4
��������Ҫ�������ֵ��666
	
���ҵ�2�������������ֵ,�Ѳ���������
�����и����ڵ����ֵΪ��
1       2       3       3       4
666     4       666     5       2
31      123     433     2
	  
������Ҫɾ������ֵ��4
�����и����ڵ����ֵΪ��
1       2       3       3       666
666     5       2       31      123
433     2

--------------------------
    �ܽ᣺Ҫ����Ϥָ��ͽṹ��Ľ��ʹ��
*/
