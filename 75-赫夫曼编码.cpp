/*
	2017年1月9日21:23:05 开始
	2017年1月9日22:22:27 休息

	2017年1月10日10:45:40 开始
	2017年1月10日11:33:33 完成，开始检查错误
	2017年1月10日11:46:38 调试成功
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct TreeNode
{
	char symbol;
	struct TreeNode * left;
	struct TreeNode * right;
} TREENODE, * PTREENODE;

typedef struct Tree
{
	PTREENODE root;
}TREE, * PTREE;

typedef struct QueueNode
{
	PTREENODE val;
	unsigned int priority;
	struct QueueNode * next;
} QUEUENODE, * PQUEUENODE;

typedef struct Queue
{
	PQUEUENODE first;
	unsigned int size;
} QUEUE, * PQUEUE;

typedef struct TQNode
{
	char * code;
	char symbol;
	struct TQNode * next;
} TQNODE, * PTQNODE;

typedef struct Table
{
	PTQNODE first;
	PTQNODE last;
} TABLE, * PTABLE;

PTREE BuildTree(char * String);
void Init_Queue(PQUEUE * queue);
void AddQueue(PQUEUE pQueue, PTREENODE val, unsigned int priority);
PTREENODE GetQTNode(PQUEUE pQueue);
PTABLE BuildTable(PTREE tree);
void TraverseTree(PTREENODE node, PTABLE table, int k, char * code);
void EnCode(PTABLE table, char * String);
void DeCode(PTREE tree, char * String);

int main(void)
{
	PTREE codetree = BuildTree("I will be a legend!");

	PTABLE codetable = BuildTable(codetree);
	
	EnCode(codetable, "I will be a legend!");

	DeCode(codetree, "10111011000001011011001111");

	system("pause");
	return 0;
}

PTREE BuildTree(char * String)
{
	int i, j, k;
	int * probability = (int *)malloc(sizeof(int)*256);

	if (NULL == probability)
	{
		printf("Failed to allocate memory space!");
		system("pause");
		exit(0);
	}

	//初始化
	for(i=0; i<256; i++)
		probability[i] = 0;

	//计算待编码字符串各个字符的个数
	for (j=0; String[j]!='\0'; j++)
		probability[(unsigned char)String[j]]++;

	//初始化赫夫曼队列
	PQUEUE pQueue;
	Init_Queue(&pQueue);

	//填充队列
	for (k=0; k<256; k++)
	{
		if (probability[k] != 0)
		{
			PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));
			if (NULL == aux)
			{
				printf("Failed to allocate memory space!");
				system("pause");
				exit(0);
			}
			aux->symbol = k;
			aux->left = aux->right = NULL;
			
			AddQueue(pQueue, aux, probability[k]);
		}	
	}
	free(probability);

	//生成赫夫曼树
	while (pQueue->size != 1)
	{
		int priority = pQueue->first->priority + pQueue->first->next->priority;
		PTREENODE left = GetQTNode(pQueue);
		PTREENODE right = GetQTNode(pQueue);

		PTREENODE newNode = (PTREENODE)malloc(sizeof(TREENODE));
		if (NULL == newNode)
		{
			printf("Failed to allocate memory space!");
			system("pause");
			exit(0);
		}
		newNode->left = left;
		newNode->right = right;
		
		AddQueue(pQueue, newNode, priority);
	}
	
	PTREE tree = (PTREE)malloc(sizeof(TREE));
	if (NULL == tree)
	{
		printf("Failed to allocate memory space!");
		system("pause");
		exit(0);
	}
	tree->root = GetQTNode(pQueue);

	return tree;
}

void Init_Queue(PQUEUE * queue)
{
	*queue = (PQUEUE)malloc(sizeof(QUEUE));
	if (NULL == *queue)
	{
		printf("Failed to allocate memory space!");
		system("pause");
		exit(0);
	}
	(*queue)->first = NULL;
	(*queue)->size = 0;
}

void AddQueue(PQUEUE pQueue, PTREENODE val, unsigned int priority)
{
	if (pQueue->size == 256)
	{
		printf("\nQueue is full.\n");
		system("pause");
		return;
	}
	PQUEUENODE aux = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	if (NULL == aux)
	{
		printf("Failed to allocate memory space!");
		system("pause");
		exit(0);
	}
	aux->priority = priority;
	aux->val = val;
	
	if (pQueue->first==NULL || pQueue->size==0)
	{
		pQueue->first = aux;
		aux->next = NULL;
		pQueue->size = 1;
	}
	else
	{
		if (aux->priority <= pQueue->first->priority)
		{
			aux->next = pQueue->first;
			pQueue->first = aux;
			pQueue->size++;
			return;
		}
		else
		{
			PQUEUENODE iterator = pQueue->first;

			while (iterator->next != NULL)
			{
				if (aux->priority <= iterator->next->priority)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					pQueue->size++;
					return;
				}
				iterator = iterator->next;
			}
			if (iterator->next == NULL)
			{
				iterator->next = aux;
				aux->next = NULL;
				pQueue->size++;
				return;
			}
		}
	}
}

PTREENODE GetQTNode(PQUEUE pQueue)
{
	PTREENODE val;
	if (pQueue->size > 0)
	{
		val = pQueue->first->val;
		pQueue->first = pQueue->first->next;
		return val;
		
	}
	else
	{
		printf("Queue is empty!\n");
		return NULL;
	}
}

PTABLE BuildTable(PTREE tree)
{
	PTABLE table = (PTABLE)malloc(sizeof(TABLE));
	if (NULL == table)
	{
		printf("Failed to allocate memory space!");
		system("pause");
		exit(0);
	}
	table->first = table->last = NULL;

	int k = 0;
	char code[256];

	TraverseTree(tree->root, table, k, code);

	return table;
}

void TraverseTree(PTREENODE node, PTABLE table, int k, char * code)
{
	if (node->left==NULL && node->right==NULL)
	{
		code[k] = '\0';
		PTQNODE aux = (PTQNODE)malloc(sizeof(TQNODE));
		if (NULL == aux)
		{
			printf("Failed to allocate memory space!");
			system("pause");
			exit(0);
		}
		aux->symbol = node->symbol;
		aux->code = (char *)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(aux->code, code);
		aux->next = NULL;

		if (table->first == NULL)
		{
			table->first = table->last = aux;		
		}
		else
		{
			table->last->next = aux;
			table->last = aux;
		}
	}
	else
	{
		if (node->left != NULL)
		{
			code[k] = '0';
			TraverseTree(node->left, table, k+1, code);
		}
		if (node->right != NULL)
		{
			code[k] = '1';
			TraverseTree(node->right, table, k+1, code);
		}
	}
}

void EnCode(PTABLE table, char * String)
{
	int i;
	PTQNODE traversal;

	printf("String:%s\n\nEncode:\n", String);
	for (i=0; String[i]!='\0'; i++)
	{
		traversal = table->first;

		while (traversal->symbol != String[i])
			traversal = traversal->next;

		printf("%s", traversal->code);
	}
	printf("\n");
}

void DeCode(PTREE tree, char * String)
{
	PTREENODE node = tree->root;
	int i;

	printf("\nString:%s\n\nDecode:\n", String);
	for (i=0; String[i]!='\0'; i++)
	{
		if (node->left==NULL && node->right==NULL)
		{
			printf("%c", node->symbol);
			node = tree->root;
		}
		if (String[i] == '0')
			node = node->left;

		if (String[i] == '1')
			node = node->right;

		if (String[i]!='0' && String[i]!='1')
		{
			printf("The input string is not coded correctly!\n");
			return;
		}
	}
	if (node->left==NULL && node->right==NULL)
	{
		printf("%c", node->symbol);
		node = tree->root;
	}

	printf("\n\n");
}