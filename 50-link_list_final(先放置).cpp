/*
	Ŀ�ģ�����һ�����ӡ���ϸ���ķ�ѭ��������Ҳ����bug���٣����ܸ��á�
		
		���磺
			1.��scanf���ж�����ֹ�û�����������Ϣ�������������ַ����ų��򣬶��ַ�������ǰ��˳�򶼽����ж�����point��
			2.����������������
			3.�����ϵ���������������������ݵ����࣬��͹�������ѧ����ְ������Ϣ�Ĳ�ͬ����Ӧ����������hard��
			4.�������Ի��Ľ���
			5.�����뵽��ô��

		���裺
			1.����һ�����Ի����档��important��
			2.��������,����õ���ֵ�ɴ�����get_int������á�
			3.�������
			4.�������ڵ㣨λ�����û��Զ��壩��
			5.����ָ�����ж��ڵ��ɾ����
			6.�����������������

		˼·��1.���������ֵ�����ͣ���1�����ʹ�������Ļ���Ҫ��֤�����������ַ��ĸ��š�
									��2�����ʹ���ַ����������Ļ���Ҫ����ת�������ǳ�������Ч�ʻ��½�.
										 ������ʹ��atoi��atof�������ַ����е�����ת��int��double��
										 ��ʵ�����Լ����Դ���һ�������ƹ��ܵĺ�����
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
// 	int number; //ѧ��
// 	char name[15]; //����
// 	int score[3]; //�ɼ�������.��ѧ.Ӣ��
// 	struct Student * pNext;
// };
// struct Restaurant{
// 	int number; //���
// 	char name[15]; //ԤԼ��
// 	char time[10]; //ԤԼʱ��
// 	int person; //ԤԼ����
// 	struct Restaurant * pNext;
// };
// 
// Creat_list(struct List * pH);
// Creat_Student(struct Student * pH);
// Creat_Restaurant(struct Restaurant * pH);
//ģʽѡ��
// int menu_Mode();
//����ѡ��
// int menu_function_list();
// int menu_function_Student();
// int menu_function_Restaurant();
//�������
// void Traverse_list(struct List * pH);
// void Traverse_Student(struct Student * pH);
// void Traverse_Restaurant(struct Restaurant * pH);
//��������
// void Search_list(struct List * pH);
// void Search_Student(struct Student * pH);
// void Search_Restaurant(struct Restaurant * pH);
//��������
// void Insert_list(struct List * pH);
// void Insert_Student(struct Student * pH);
// void Insert_Restaurant(struct Restaurant * pH);
//����ɾ��
// void Delete_list(struct List * pH);
// void Delete_Student(struct Student * pH);
// void Delete_Restaurant(struct Restaurant * pH);
//�������
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
			printf("��");
			continue;
		}
		if (i == M/2)
		{
			printf("��");
			continue;
		}
		if (i == M-1)
		{
			printf("��");
			continue;
		}
		printf("��");
	}

	printf("��");
	for (k=0; k<((j/2)+(j%2)); k++) //�Ʊ���м��� //���ԣ���������ѡ������
	{
		for (j=0; j<Size; j++) //һ����������ѡ�����һ��ֻ����ʾ��
		{
			for(i=strlen(a[j]-1); i<M/2; i++)
			{
				printf(" ");
				if (i = M/2-1)
				{
					printf("��");
					continue;			
				}
			}
		}
		printf("\n");
		if (k == 0) //��
		{
			for(i=0; i<M; i++)
			{	
				if (i == 0)
				{
					printf("��");
					continue;
				}
				if (i == M/2)
				{
					printf("��");
					continue;
				}
				if (i == M-1)
				{
					printf("��");
					continue;
				}
				printf("��");	
			}
			printf("\n");
		}
		else if (k = ((j/2)+(j%2)-1)) //��
		{
			for(i=0; i<M; i++)
			{
				if (i == 0)
				{
					printf("��");
					continue;
				}
				if (i == M/2)
				{
					printf("��");
					continue;
				}
				if (i == M-1)
				{
					printf("��");
					continue;
				}
				printf("��");
			}
			printf("\n");
		}
		else 
		{
			for(i=0; i<M; i++) //ÿ��ѡ�����м�ķָ��� //��
			{
				if (i == 0)
				{
					printf("��");
					continue;
				}
				if (i == M/2)
				{
					printf("��");
					continue;
				}
				if (i == M-1)
				{
					printf("��");
					continue;
				}
				printf("��");
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

//�������
// void Traverse_list(struct List * pH);
// void Traverse_Student(struct Student * pH);
// void Traverse_Restaurant(struct Restaurant * pH);
//��������
// void Search_list(struct List * pH);
// void Search_Student(struct Student * pH);
// void Search_Restaurant(struct Restaurant * pH);
//��������
// void Insert_list(struct List * pH);
// void Insert_Student(struct Student * pH);
// void Insert_Restaurant(struct Restaurant * pH);
//����ɾ��
// void Delete_list(struct List * pH);
// void Delete_Student(struct Student * pH);
// void Delete_Restaurant(struct Restaurant * pH);
//�������
// void clear_list(struct List * pH);
// void clear_Student(struct Student * pH);
// void clear_Restaurant(struct Restaurant * pH);;
