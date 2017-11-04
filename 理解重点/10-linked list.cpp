/*	
	2016年11月8日13:03:59

实验目的：创建一个非循环单链表
步骤：
	1.调用链表：（main函数）
		先在main函数定义一个存放头结点地址的变量pHead为NULL
		让把Create_List返回的指针变量赋给pHead
		再调用Create_List输出链表中的数值

	2.创建链表：（Create_List函数）
		分配一个不存放有效数据的头结点pHead并判断其是否为NULL
		定义一个存放尾结点地址的变量pTail
		先定义val=0，再做循环，当val为1结束循环
		当循环结束后n为2，即没有创建链表，直接结束运行
		每次循环分配一个新节点pNew
		判断pNew指针变量是否为NULL
		输入想要存入链表的数值val
		让pNew->data = val，然后pTail->pNext指向pNew
		再让pNew->pNext = NULL，最后让pTail指向pNew

	3.输出链表：（Traverse_List函数中）
		定义一个struct Node * p指向pHead->pNext
		做循环，让p不等于NULL，每次输出data并指向下一个节点
		再适当进行输出美观工作，保证阅读的清晰性

	4.链表的搜索（找到提示有，否则无）
		定义一个struct Node * p指向pHead
		让用户输入想要搜索的数值
		做for循环，条件为p不为NULL
		每轮循环判断p->data == val，让计数标量n++
		循环结束后令p指向p->pNext
		最后再输出结果

	5.链表插入节点
		让用户输入想要在那个数值val后插入的值和想要插入的数值number
		做for循环，初始化struct Node * p等于参数pHead，条件为p!=NULL
		每轮循环中新分配一个空间pNew，判断p->data等不等于val
		如果相等，则让pNew->pNext= p->pNext;   p->pNext = pNew;
		pNew->data = number; p=p->pNext; n++;  n为计数变量
		循环之后再让p指向下一个
		如果搜索条件符合(n!=0)，以上步骤就已经完成，只需输出结果
		如果搜索条件不符合(n == 0)，再次令用户输入数值，再次重复以上步骤
		
	6.链表删除指定节点
		让用户输入想要删除的节点相对应的数值val
		定义struct Node * p = pHead; struct Node * pTail = p->pNext;
		做for循环，每轮条件为pTail不为NULL并判断val等不等于pTail->data
		如果相等，让p->pNext = pTail->pNext; 释放pTail的空间
		不相等则让p指向下一个 ， 再做遍历输出结果

	7.释放链表空间（删除链表）
		定义一个struct Node * p结构体p指向pHead
		做for循环，条件为pHead不为NULL
		每轮循环让p指向p->pNext,再把pHead的空间释放掉
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
	
	pHead = Create_List(); //创建链表
	Traverse_List(pHead);  //输出链表（遍历输出）
	Search_List(pHead);    //链表的搜索（搜索指定数值的节点是否存在）	
	Insert_List(pHead);    //链表的插入（在指定数值之后插入新节点）
	Delete_List(pHead);    //链表的删除（删除指定数值的节点）	
	Clear_List(pHead);     //链表的清除（释放空间）

	system("pause");
	return 0;
}

struct Node * Create_List(void) //创建链表
{
	int i=1, val=0;
	
	struct Node * pHead = (struct Node *)malloc(sizeof(struct Node)); //定义一个空的头结点
	struct Node * pTail = pHead;
	if (pHead == NULL)
	{
		printf("分配空间失败！\n");
		exit(-1);
	}

	printf("(注意：请输入整数 [-32768 ~ 32767]，该链表以 -1 结束输入)\n");
	while (val != -1)
	{
		struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
		if (pNew == NULL)
		{
			printf("分配空间失败！\n");
			exit(-1);
		}

		printf("输入第%d个节点的数值(整数)：", i);
		scanf("%d", &val);

		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
		++i;
	}
	if(i == 2)
	{
		printf("创建链表失败\n");
		exit(-1);
	}
	return pHead;
}

void Traverse_List(struct Node * pHead) //输出链表（遍历输出）
{
	struct Node * p = pHead->pNext;
	int cnt=0, i;
	printf("链表中各个节点的数值为：\n");
	for (i=1; NULL != p; ++i)
	{
		if(p->data == -1) //以data为-1结束的数值
			break;
		if(i<10) //为了使输出的链表对齐
			printf("[%d]:%-10d", i, p->data);
		else if (i<100)
			printf("[%d]:%-9d", i, p->data);
		else
			printf("[%d]:%-8d", i, p->data);
		p = p->pNext;
		
		// 美观
		++cnt;
		if(0==cnt%5 && cnt!=0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

void Search_List(struct Node * pHead) //链表的搜索（搜索指定数值的节点是否存在）
{
	struct Node * p;
	int val, n=0, i;
	printf("\n请输入要搜索的数值：");
	scanf("%d", &val);

	for(p=pHead,i=0; p; p=p->pNext,++i)//当pHead==NULL停止循环
		if(p->data == val)
		{
			n++;
			printf("[%d]  ", i);
		}

	if (n != 0)
		printf("位置上共找到%d个符合的数值！\n", n);
	else
		printf("没有找到该数值！\n");
}

void Insert_List(struct Node * pHead) //链表的插入（在指定数值之后插入新节点）
{
	int val, n=0, number;
	struct Node * p;
	
	printf("\n请输入要在哪个数值之后插入数值：");
	scanf("%d", &val);
	printf("请输入想要插入的数值：");
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
		printf("未找到符合条件的数值！请再次输入：");
		scanf("%d", &val);
		for(p=pHead; p; p=p->pNext)
		{
			struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
			if (pNew == NULL)
			{
				printf("分配空间失败！\n");
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
		printf("\n共找到%d项符合条件的数值,已插入链表中\n", n);
		Traverse_List(pHead);
	}
}

void Delete_List(struct Node * pHead) //链表的删除（删除指定数值的节点）
{
	int val;
	struct Node * p;
	struct Node * pTail;

	printf("\n请输入要删除的数值：");
	scanf("%d", &val);
	
	for(p = pHead,pTail=p->pNext; pTail; pTail=p->pNext)
	{
		if (val==pTail->data) //条件成功不必让p指向下一个
		{
			p->pNext = pTail->pNext;
			free(pTail);
		}
		else
			p=p->pNext;

	}

	Traverse_List(pHead);
}

void Clear_List(struct Node * pHead) //链表的清除（释放空间）
{
	struct Node * p;
	while(NULL != pHead)
	{
		p = pHead->pNext;
		free(pHead);
		pHead = p;
	}
}

/*在Vc++6.0中的输出结果是：
--------------------------
输入第1个节点的数值(整数)：1
输入第2个节点的数值(整数)：2
输入第3个节点的数值(整数)：3
输入第4个节点的数值(整数)：3
输入第5个节点的数值(整数)：4
输入第6个节点的数值(整数)：4
输入第7个节点的数值(整数)：5
输入第8个节点的数值(整数)：2
输入第9个节点的数值(整数)：31
输入第10个节点的数值(整数)：123
输入第11个节点的数值(整数)：433
输入第12个节点的数值(整数)：2
输入第13个节点的数值(整数)：-1
链表中各个节点的数值为：
1       2       3       3       4
4       5       2       31      123
433     2

请输入要搜索的数值：3
共找到2个符合数值！
  
请输入要在哪个数值之后插入数值：4
请输入想要插入的数值：666
	
共找到2项符合条件的数值,已插入链表中
链表中各个节点的数值为：
1       2       3       3       4
666     4       666     5       2
31      123     433     2
	  
请输入要删除的数值：4
链表中各个节点的数值为：
1       2       3       3       666
666     5       2       31      123
433     2

--------------------------
    总结：要多熟悉指针和结构体的结合使用
*/
