# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAXSIZE 256

typedef struct TreeNode
{
	char symbol;
	struct TreeNode * left;
	struct TreeNode * right;
} TREENODE, * PTREENODE;
typedef struct Tree
{
	PTREENODE root;
} TREE, * PTREE;
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
}TQNODE, * PTQNODE;
typedef struct Table
{
	PTQNODE first;
	PTQNODE last;
} TABLE, * PTABLE;

PTREE BuildTree(char * String);
void Init_Queue(PQUEUE * queue);
PTREENODE GetQTreeNode(PQUEUE queue);
void AddQueue(PQUEUE queue, PTREENODE val, unsigned int priority);
PTABLE BuildTable(PTREE tree);
void TraverseTree(PTREENODE traversal, PTABLE table, int k, char * code);
void Encode(PTABLE table, char *StringToEncode);
void Decode(PTREE tree, char * StringToDecode);

int main(void)
{
	PTREE codetree = BuildTree("Have you ever forgotten me?");

	PTABLE codetable = BuildTable(codetree);

	Encode(codetable, "Have you ever forgotten me?");

	Decode(codetree, "10001011101001100100010001111101010111001111");

	system("pause");
	return 0;
}

PTREE BuildTree(char * String)
{
	int i, j, k;
	int * probability = (int *)malloc(sizeof(int)*MAXSIZE);
	if (NULL == probability)
	{
		printf("\nFailed to allocate memory space for variables!\n");
		system("pause");
		exit(0);
	}
	
	for (i=0; i<MAXSIZE; i++)
		probability[i] = 0;
	for (j=0; String[j]!='\0'; j++)
		probability[(unsigned char)String[j]]++;

	PQUEUE pQueue = (PQUEUE)malloc(sizeof(QUEUE));
	if(NULL == pQueue)
	{
		printf("\nFailed to allocate memory space for variables!\n");
		system("pause");
		exit(0);
	}
	Init_Queue(&pQueue);

	for (k=0; k<MAXSIZE; k++)
	{
		if (probability[k] != 0)
		{
			PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));
			if (NULL == aux)
			{
				printf("\nFailed to allocate memory space for variables!\n");
				system("pause");
				exit(0);
			}
			aux->symbol = k;
			aux->left = aux->right = NULL;
			
			AddQueue(pQueue, aux, probability[k]);
		}
	}

	free(probability);

	while (pQueue->size != 1)
	{
		int priority = pQueue->first->priority + pQueue->first->next->priority;

		PTREENODE left = GetQTreeNode(pQueue);
		PTREENODE right = GetQTreeNode(pQueue);

		PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));
		if (NULL == aux)
		{
			printf("\nFailed to allocate memory space for variables!\n");
			system("pause");
			exit(0);
		}

		aux->left = left;
		aux->right = right;

		AddQueue(pQueue, aux, priority);
	}

	PTREE tree = (PTREE)malloc(sizeof(TREE));
	if (NULL == tree)
	{
		printf("\nFailed to allocate memory space for variables!\n");
		system("pause");
		exit(0);
	}
	tree->root = GetQTreeNode(pQueue);

	return tree;
}

void Init_Queue(PQUEUE * queue)
{
	*queue = (PQUEUE)malloc(sizeof(QUEUE));
	if (NULL == queue)
	{
		printf("\nFailed to allocate memory space for variables!\n");
		system("pause");
		exit(0);
	}
	(*queue)->first = NULL;
	(*queue)->size = 0;
}

PTREENODE GetQTreeNode(PQUEUE queue)
{
	PTREENODE val = NULL;

	if (queue->size > 0)
	{
		val = queue->first->val;
		queue->first = queue->first->next;
		queue->size--;
	}
	else
		printf("\nQueue is empty!\n");
	
	return val;
}

void AddQueue(PQUEUE queue, PTREENODE val, unsigned int priority)
{
	if (queue->size == MAXSIZE)
	{
		printf("\nQueue is full!\n");
		return;
	}
	else
	{
		PQUEUENODE newQNode = (PQUEUENODE)malloc(sizeof(QUEUENODE));
		if (NULL == newQNode)
		{
			printf("\nFailed to allocate memory space for variables!\n");
			system("pause");
			exit(0);
		}
		newQNode->priority = priority;
		newQNode->val = val;

		if (queue->first==NULL || queue->size==0)
		{
			queue->first = newQNode;
			newQNode->next = NULL;
			queue->size = 1;
			return;
		}
		else
		{
			if (priority <= queue->first->priority)
			{
				newQNode->next = queue->first;
				queue->first = newQNode;
				queue->size++;
				return;
			}
			else
			{
				PQUEUENODE iterator = queue->first;
				
				while (iterator->next != NULL)
				{
					if (iterator->next->priority >= priority)
					{
						newQNode->next = iterator->next;
						iterator->next = newQNode;
						queue->size++;
						return;
					}
					iterator = iterator->next;
				}
				
				if (iterator->next == NULL)
				{
					iterator->next = newQNode;
					newQNode->next = NULL;
					queue->size++;
					return;
				}
			}	
		}
	}
}

PTABLE BuildTable(PTREE tree)
{
	int k = 0;
	char code[256];

	PTABLE table = (PTABLE)malloc(sizeof(TABLE));
	if (NULL == table)
	{
		printf("\nFailed to allocate memory space for variables!\n");
		system("pause");
		exit(0);
	}
	table->first = table->last = NULL;

	TraverseTree(tree->root, table, k, code);

	return table;
}

void TraverseTree(PTREENODE traversal, PTABLE table, int k, char * code)
{
	if (traversal->left==NULL && traversal->right==NULL)
	{
		code[k] = '\0';
		PTQNODE aux = (PTQNODE)malloc(sizeof(TQNODE));
		aux->code = (char *)malloc(sizeof(char)*(strlen(code)+1));
		if (NULL==aux || NULL==aux->code)
		{
			printf("\nFailed to allocate memory space for variables!\n");
			system("pause");
			exit(0);
		}

		strcpy(aux->code, code);
		aux->symbol = traversal->symbol;
		aux->next = NULL;

		if (table->first == NULL)
			table->first = table->last = aux;
		else
		{
			table->last->next = aux;
			table->last = aux;
		}
	}
	if (traversal->left != NULL)
	{
		code[k] = '0';
		TraverseTree(traversal->left, table, k+1, code);	
	}
	if (traversal->left != NULL)
	{
		code[k] = '1';
		TraverseTree(traversal->right, table, k+1, code);	
	}
}

void Encode(PTABLE table, char * StringToEncode)
{
	PTQNODE traversal;
	int i;

	printf("StringToEncode:\n%s\n\nEncode:\n", StringToEncode);
	for (i=0; StringToEncode[i]!='\0'; i++)
	{
		traversal = table->first;

		while (traversal->symbol != StringToEncode[i])
			traversal = traversal->next;

		printf("%s", traversal->code);
	}
	printf("\n");
}

void Decode(PTREE tree, char * StringToDecode)
{
	PTREENODE traversal = tree->root;
	int i;

	printf("\nStringToDecode:\n%s\n\nDecode:\n", StringToDecode);
	for (i=0; StringToDecode[i]!='\0'; i++)
	{
		if (traversal->left==NULL && traversal->right==NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		if (StringToDecode[i] == '0')
			traversal = traversal->left;
		else if (StringToDecode[i] == '1')
			traversal = traversal->right;
		else
		{
			printf("Decoding error!\n");
			return;
		}
	}
	if (traversal->left==NULL && traversal->right==NULL)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}
	printf("\n");
}