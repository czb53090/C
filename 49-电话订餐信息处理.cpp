/*
	目的：制作一张电话清单，内容为（名字 时间 人数）其功能包括：
			1.插入-----Insert
			2.查询-----Search
			3.修改-----Update
			4.删除-----Delete
			5.显示-----Show
			6.退出-----Exit
*/
# include <stdio.h>
# include <stdlib.h>
# define N 20

struct guest_info
{
	int num;		//编号
	char name[15];  //名字
	char time[10];  //时间
	int sum;		//人数
};

void Insert(struct guest_info * pGuest);
void Search(struct guest_info * pGuest);
void Update(struct guest_info * pGuest);
void Delete(struct guest_info * pGuest);
void Show(struct guest_info * pGuest);


int main(void)
{
	struct guest_info guest[N]={0}, * pGuest=guest;
	int i;

	printf("	Welcome to use the Reservation management system:\n");
	printf("\n");
	printf("<1>Insert  <2>Search  <3>Update  <4>Delete  <5>Show  <6>exit\n");
	do
	{	
		printf("Choose the function you want:");
		scanf("%d", &i);

		switch (i)
		{
		case 1: Insert(pGuest); break;
		case 2: Search(pGuest); break;
		case 3: Update(pGuest); break;
		case 4: Delete(pGuest); break;
		case 5: Show(pGuest); break;
		case 6: break;
		default:printf("error,please enter again"); break;
		}
	} while (i != 6);

	system("pause");
	return 0;
}

void Insert(struct guest_info * pGuest)
{
	int i;
	char ch;
	struct guest_info guest_insert;

	printf("please input the guest's info(example：number name time person):\n");
		for (i=0; i<N ; i++)
		{
			if ((pGuest+i)->num == 0)
			{		
				printf("Enter guest's info:");
				scanf("%d %s %s %d", &guest_insert.num, guest_insert.name, guest_insert.time, &guest_insert.sum);
				*(pGuest+i) = guest_insert;
				if (i>0 && (pGuest+i-1)->num>=guest_insert.num)
				{
					printf("The number is small,enter again!\n");
					(pGuest+i)->num = 0;
					i--;
					continue;
				}
				printf("Do you want to continue(y/n);");
				scanf(" %c", &ch);
				if (ch=='n' || ch=='n')
					break;
			}
		}
}

void Search(struct guest_info * pGuest)
{
	int number, i, flag=1;

	printf("input the number you want to search:");
	scanf("%d", &number);
	for (i=0; i<N; i++)
		if ((pGuest+i)->num == number)
		{
			printf("Is found:num:%d name:%s time:%s person:%d\n", (pGuest+i)->num, (pGuest+i)->name, (pGuest+i)->time, (pGuest+i)->sum);
			flag=0;
			break;
		}
	if (flag)
		printf("Not found!\n");
}

void Update(struct guest_info * pGuest)
{
	int number, i;
	char ch;

	do
	{
		int flag = 1;
		printf("input the number you want to change:");
		scanf("%d", &number);
		for (i=0; i<N; i++)
			if ((pGuest+i)->num == number)
			{
				printf("Is found,now change(example:time person):");
				scanf("%s %d", &(pGuest+i)->time, &(pGuest+i)->sum);
				flag = 0;
				break;
			}
		if (flag) printf("No found!\n");
		printf("Do you want to continue(y/n);");
		scanf(" %c", &ch);
	} while (ch=='y' || ch=='y');
}

void Delete(struct guest_info * pGuest)
{
	int i, j=0, number;
	char ch;

	do 
	{
		int flag = 1;

		printf("input the number you want to delete:");
		scanf("%d", &number);

		for (i=0; i<N; i++,j=0)
			if ((pGuest+i)->num == number)
			{
				printf("Is found and delete!");
				if ((pGuest+i+1)->num == 0)
					(pGuest+i)->num = 0;
				for (j=i; j<N && (pGuest+j+1)->num!=0; j++)
					*(pGuest+j) = *(pGuest+j+1);
				if (j>i)
					(pGuest+j)->num = 0;
				flag = 0;
			}

		if (j>i) (pGuest+j)->num = 0;
		if (flag) printf("No found!\n");

		printf("Do you want to continue(y/n);");
		scanf(" %c", &ch);
	} while (ch=='y' || ch=='y');

}

void Show(struct guest_info * pGuest)
{
	int i;

	printf("The guest list is:\n");
	for (i=0; i<N; i++)
	{
		if ((pGuest+i)->num == 0)
			break;
		printf("num:%d name:%s time:%s person:%d\n", (pGuest+i)->num, (pGuest+i)->name, (pGuest+i)->time, (pGuest+i)->sum);
	}
	printf("\n");
}