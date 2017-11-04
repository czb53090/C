/*
	目的：制作一个更加“精细”的非循环单链表，也就是bug更少，功能更好。
		
		例如：
			1.对scanf的判定，防止用户输入错误的信息，如输入其他字符干扰程序，对字符的输入前后顺序都进行判定。【point】
			2.可以输入更多的数据
			3.功能上的提升（如输入链表的数据的种类，如餐馆名单，学生，职工等信息的不同而相应调整，）【hard】
			4.更加人性化的界面
			5.暂且想到这么多

		步骤：
			1.构建一个人性化界面。【important】
			2.创建链表,输入得到的值可创建由get_int函数获得。
			3.输出链表。
			4.链表插入节点（位置由用户自定义）。
			5.链表指定或判定节点的删除。
			6.清除链表（结束链表）。

		思路：1.针对输入数值的类型：（1）如果使用整数的话，要保证整数中其他字符的干扰。
									（2）如果使用字符代替整数的话，要进行转换，但是程序运行效率会下降.
										 但可以使用atoi和atof函数吧字符串中的数字转换int和double。
										 其实可以自己尝试创建一个有类似功能的函数。
*/

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>
# include "50-link_list_final.h"
# define N 5
# define M 36
# define Size 6

// struct List{
// 	int number;
// 	int val;
// 	struct List * pNext;
// };
// struct Student{
// 	int number; //学号
// 	char name[15]; //名字
// 	int score[3]; //成绩：语文.数学.英语
// 	struct Student * pNext;
// };
// struct Restaurant{
// 	int number; //序号
// 	char name[15]; //预约人
// 	char time[10]; //预约时间
// 	int person; //预约人数
// 	struct Restaurant * pNext;
// };
// 
// Creat_list(struct List * pH);
// Creat_Student(struct Student * pH);
// Creat_Restaurant(struct Restaurant * pH);
//模式选择
// int menu_Mode();
//功能选择
// int menu_function_list();
// int menu_function_Student();
// int menu_function_Restaurant();
//链表遍历
// void Traverse_list(struct List * pH);
// void Traverse_Student(struct Student * pH);
// void Traverse_Restaurant(struct Restaurant * pH);
//链表搜索
// void Search_list(struct List * pH);
// void Search_Student(struct Student * pH);
// void Search_Restaurant(struct Restaurant * pH);
//链表搜索
// void Insert_list(struct List * pH);
// void Insert_Student(struct Student * pH);
// void Insert_Restaurant(struct Restaurant * pH);
//链表删除
// void Delete_list(struct List * pH);
// void Delete_Student(struct Student * pH);
// void Delete_Restaurant(struct Restaurant * pH);
//链表清除
// void clear_list(struct List * pH);
// void clear_Student(struct Student * pH);
// void clear_Restaurant(struct Restaurant * pH);;


int main()
{
	int flag = 1, n, num;
	struct List * pH1;
	struct Student * pH2;
	struct Restaurant * pH3;

	menu_function_list();
	
// 	while (flag)
// 	{
// 		n = menu_Mode();
// 		switch (n-1)
// 		{
// 		case 0:
// 			Creat_list(pH1);
// 			num = menu_function_list();
// 			switch (num-1)
// 			{
// 			case 0: Search_list(pH1); break;
// 			case 1: Insert_list(pH1); break;
// 			case 2: Delete_list(pH1); break;
// 			case 3: Clear_list(pH1);  break;
// 			}
// 			flag = 0;
// 			break;
// 		case 1:
// 			Creat_Student(pH2);
// 			num = menu_function_Student();
// 			switch (num-1)
// 			{
// 			case 0: Search_Student(pH1); break;
// 			case 1: Insert_Student(pH1); break;
// 			case 2: Delete_Student(pH1); break;
// 			case 3: Clear_Student(pH1);  break;
// 			}
// 			flag = 0;
// 			break;
// 		case 2:
// 			Creat_Restaurant(pH3);
// 			num = menu_function_Restaurant()
// 				switch (num-1)
// 			{
// 			case 0: Search_Restaurant(pH1); break;
// 			case 1: Insert_Restaurant(pH1); break;
// 			case 2: Delete_Restaurant(pH1); break;
// 			case 3: Clear_Restaurant(pH1);  break;
// 			}
// 			
// 			flag = 0;
// 			break;
// 		default: printf("Please input the right number:"); break;
// 		}
	
	system("pause");
	return 0;
}

int menu_Mode()
{
	int n;
	printf("Choise the mode(1.normal;2.student;3.restaurant):");
	scanf("%d", &n);
	while (getchar()!='\0') continue;
	return n;
}

int menu_function_list()
{
	int n, i, j, k;
	char * a[Size] = {
		"Please input the number to chose the funtion you want",
		"1.Search",
		"2.Insert",
		"3.Delete",
		"4.Creat a new Link_list",
		"5.Quit",
	};
	printf("		Welcome to Use the basic mode\n");

	for(i=0; i<M; i++)
	{
		if (i == 0)
		{
			printf("┏");
			continue;
		}
		if (i == M/2)
		{
			printf("┳");
			continue;
		}
		if (i == M-1)
		{
			printf("┓");
			continue;
		}
		printf("━");
	}

	printf("┃");
	for (k=0; k<((j/2)+(j%2)); k++) //制表框有几行 //不对，还包括非选择项行
	{
		for (j=0; j<Size; j++) //一行中有两个选项，但第一项只是提示语
		{
			for(i=strlen(a[j]-1); i<M/2; i++)
			{
				printf(" ");
				if (i = M/2-1)
				{
					printf("┃");
					continue;			
				}
			}
		}
		printf("\n");
		if (k == 0) //√
		{
			for(i=0; i<M; i++)
			{	
				if (i == 0)
				{
					printf("┣");
					continue;
				}
				if (i == M/2)
				{
					printf("╋");
					continue;
				}
				if (i == M-1)
				{
					printf("┫");
					continue;
				}
				printf("━");	
			}
			printf("\n");
		}
		else if (k = ((j/2)+(j%2)-1)) //√
		{
			for(i=0; i<M; i++)
			{
				if (i == 0)
				{
					printf("┗");
					continue;
				}
				if (i == M/2)
				{
					printf("┻");
					continue;
				}
				if (i == M-1)
				{
					printf("┛");
					continue;
				}
				printf("━");
			}
			printf("\n");
		}
		else 
		{
			for(i=0; i<M; i++) //每行选择项中间的分格线 //√
			{
				if (i == 0)
				{
					printf("┣");
					continue;
				}
				if (i == M/2)
				{
					printf("╋");
					continue;
				}
				if (i == M-1)
				{
					printf("┫");
					continue;
				}
				printf("━");
			}
			printf("\n");
		}
	}	
	scanf("%d", &n);

	return n;
}

// int menu_function_Student();
// int menu_function_Restaurant();

void Creat_list(struct List * pH)
{
	
	struct List * pHead;

	struct List * pNew = (struct List *)malloc(sizeof(struct List));
}

void Creat_Student(struct Student * pH)
{
	
}

void Creat_Restaurant(struct Restaurant * pH)
{
	
}

//链表遍历
// void Traverse_list(struct List * pH);
// void Traverse_Student(struct Student * pH);
// void Traverse_Restaurant(struct Restaurant * pH);
//链表搜索
// void Search_list(struct List * pH);
// void Search_Student(struct Student * pH);
// void Search_Restaurant(struct Restaurant * pH);
//链表搜索
// void Insert_list(struct List * pH);
// void Insert_Student(struct Student * pH);
// void Insert_Restaurant(struct Restaurant * pH);
//链表删除
// void Delete_list(struct List * pH);
// void Delete_Student(struct Student * pH);
// void Delete_Restaurant(struct Restaurant * pH);
//链表清除
// void clear_list(struct List * pH);
// void clear_Student(struct Student * pH);
// void clear_Restaurant(struct Restaurant * pH);;
