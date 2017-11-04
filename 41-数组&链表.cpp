# include <stdio.h>
# include <stdlib.h>
# define LA 4
# define LB 5

struct Student
{
	int number;
	char name[10];
	struct Student * pNext;
};

void output_list(struct Student * p, int len);

int main(void)
{
	struct Student a[LA] = {{101,"Wang"},{102,"Li"},{105,"Zhang"},{106,"Wei"}};
	struct Student b[LB] = {{103,"Zhang"},{104,"Ma"},{105,"Chen"},{107,"Guo"},{108,"Liu"}};
	struct Student * p, * p1, * p2, * head1, * head2; 
	int i;

	head1 = a;
	head2 = b;

	printf("Link-list A:\n");
	output_list(head1, LA);

	printf("\nLink-list B:\n");
	output_list(head2, LB);

	//对链表A进行的操作
	p1 = head1;
	while (p1 != NULL)
	{
		p2 = head2;
		while ((p1->number!=p2->number) && (p2->pNext!=NULL))
			p2 = p2->pNext;
		if (p1->number == p2->number)
		{
			if (p1 == head1)
				head1 = p1->pNext;
			else
			{
				p->pNext = p1->pNext;
				p1 = p1->pNext;
			}
		}
		else
		{
			p = p1;
			p1 = p1->pNext;
		}
	}

	printf("\ntesult:\n");
	p1 = head1;
	while (p1 != NULL)
	{
		printf("%4d%7s\n", p1->number, p1->name);
		p1 = p1->pNext;
	}

	system("pause");
	return 0;
}

void output_list(struct Student * p, int len)
{
	struct Student * p1 = p;
	int i;
	for (i=1; i<=len; i++)
	{
		printf("%4d%8s\n", p1->number, p1->name);
		if (i < len)
		{
			p1->pNext = p+i;
			p1 = p1->pNext;
		}
		else
			p1->pNext = NULL;
	}
}
