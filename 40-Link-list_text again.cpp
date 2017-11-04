/*
	2016年11月22日13:42:58 功能基本实现，但还有待改进，如输入的学生序号重复问题
	目的：创建一个存取学生序号和成绩的非循环单链表
*/
# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

struct Student
{
	int number;
	int score;
	struct Student * pNext;
};

struct Student * creat_list();
void output_list(struct Student * p);
void delete_list(struct Student * p);
void insert_list(struct Student * p);
void search_list(struct Student * p);
void clear_list(struct Student * p);

int main(void)
{
	struct Student * pHead;
	
	pHead = creat_list();
	delete_list(pHead);
	insert_list(pHead);
	search_list(pHead);
	clear_list(pHead);

	system("pause");
	return 0;
}

struct Student * creat_list() //创建链表
{
	int number=0, score;
	struct Student * pHead = (struct Student *)malloc(sizeof(struct Student)); //创建一个空的头结点
	struct Student * p;
	p = pHead;
	printf("input the number and score of the student(example:1 100):\n");
	while (number != -1)
	{
		scanf("%d", &number);
		if (number == -1) break;
		scanf("%d", &score);
		struct Student * pNew = (struct Student *)malloc(sizeof(struct Student)); 
		pNew->number = number;
		pNew->score = score;

		p->pNext = pNew;
		pNew->pNext = NULL;
		p = pNew;
	}
	output_list(pHead);
	return pHead;
}

void output_list(struct Student * p)
{
	printf("\nThe result of the list is:\n");
	while (p->pNext != NULL)
	{
		p = p->pNext;
		printf("number:%5d,score:%5d\n", p->number, p->score);	
	} 
}

void delete_list(struct Student * p) //链表的删除
{
	int number, flag=0;
	struct Student * p1, * p2;
	printf("\ninput the number you want delete:");
	
	while(!flag)
	{
		p1 = p;
		scanf("%d", &number);
		while (p1->pNext != NULL)
		{
			p2 = p1;
			p1 = p1->pNext;
			if (p1->number == number)
			{
				p2->pNext = p1->pNext;
				free(p1);
				output_list(p);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("error,input the number again:");
	}
	
}

void insert_list(struct Student * p) //链表的插入
{
	struct Student * pNew = (struct Student *)malloc(sizeof(struct Student));
	int n, i, m=1;
	struct Student * p1;

	while (m)
	{
		p1 = p->pNext;
		if(m==3 || m==1)
		{
			printf("input the place you want insert:");
			scanf("%d", &n);
		}
		if (m == 1)
		{
			printf("input number and score of new list:");
			scanf("%d %d", &pNew->number, &pNew->score);
			m = 2;
		}
		for (i=2; p1->pNext!=NULL; p1=p1->pNext, i++)
		{
			if (i == n)
			{
				pNew->pNext = p1->pNext;
				p1->pNext = pNew;
				printf("insert success!");
				output_list(p);
				m = 0;
			}
			if (m == 0) break;
		}
		if (m == 0) break;
		if (n > i-1)
		{
			printf("The number of place is error,please ");
			m = 3;
		}
	}
	
}

void search_list(struct Student * p) //链表的搜索
{
	int number, flag=0;
	struct Student * p1;
	printf("input a number you want search:");
	while (!flag)
	{
		p1= p;
		scanf("%d", &number);
		while (p1->pNext!=NULL)
		{
			p1=p1->pNext;
			if (number == p1->number)
			{
				printf("Is find!   number:%d  score:%d\n", p1->number, p1->score);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("Not found, please input the number again:");
	}
}

void clear_list(struct Student * p) //清除链表
{
	struct Student * pNext;
	while (p->pNext != NULL)
	{
		pNext = p->pNext;
		free(p);
		p = pNext;
	}
}