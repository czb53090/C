/*
	2017Äê1ÔÂ10ÈÕ19:15:30
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAXSIZE 256

typedef struct TreeNode
{
	char symbol;
	struct TreeNode * left, * right;
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

typedef struct TlQNode
{
	char symbol;
	char * code;
	struct TlQNode * next;
} TLQNODE, * PTLQNODE;

typedef struct Table
{
	PTLQNODE first;
	PTLQNODE last;
} TABLE, * PTABLE;

PTREE BuildTree(char * string);
void Init_Queue(PQUEUE * queue);
PTREENODE GetQTNode(PQUEUE queue);
void AddQueue(PQUEUE queue, PTREENODE val, unsigned int priority);
PTABLE BuildTable(PTREE tree);
void TraverseTree(PTREENODE traversal, PTABLE table, int k, char * code);
void Encode(PTABLE table, char * string_to_encode);
void Decode(PTREE tree, char * string_to_decode);

int main(void)
{
	PTREE codetree = BuildTree("Fllowing your heart!");

	PTABLE codetable = BuildTable(codetree);

	Encode(codetable, "Fllowing your heart!");

	Decode(codetree, "1000000000011110111111111110111010");

	system("pause");
	return 0;
}

PTREE BuildTree(char * string)
{
	int i, j, k;
	int * probability = (int *)malloc(sizeof(int)*MAXSIZE);

	for (i=0; i<MAXSIZE; i++)
		probability[i] = 0;
	for (j=0; string[j]!='\0'; j++)
		probability[(unsigned char)string[j]]++;

	PQUEUE queue = (PQUEUE)malloc(sizeof(QUEUE));
	Init_Queue(&queue);

	for (k=0; k<MAXSIZE; k++)
	{
		if (probability[k] != 0)
		{
			PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));

			aux->left = aux->right = NULL;
			aux->symbol = k;

			AddQueue(queue, aux, probability[k]);
		}
	}

	free(probability);

	while (queue->size != 1)
	{
		int priority = queue->first->priority + queue->first->next->priority;

		PTREENODE left = GetQTNode(queue);
		PTREENODE right = GetQTNode(queue);
		
		PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));

		aux->left = left;
		aux->right = right;
		
		AddQueue(queue, aux, priority);
	}
	
	PTREE tree = (PTREE)malloc(sizeof(TREE));

	tree->root = GetQTNode(queue);

	return tree;
}

void Init_Queue(PQUEUE * queue)
{
	*queue = (PQUEUE)malloc(sizeof(QUEUE));
	(*queue)->first = NULL;
	(*queue)->size = 0;
}

PTREENODE GetQTNode(PQUEUE queue)
{
	PTREENODE val = NULL;

	if (queue->size > 0)
	{
		val = queue->first->val;
		queue->first = queue->first->next;
		queue->size--;
	}
	else
	{
		printf("Queue is empty!\n");
	}

	return val;
}

void AddQueue(PQUEUE queue, PTREENODE val, unsigned int priority)
{
	if (queue->size == MAXSIZE)
	{
		printf("Queue is full!\n");
		system("pause");
		return;
	}
	
	PQUEUENODE aux = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	aux->priority = priority;
	aux->val = val;

	if (queue->first == NULL)
	{
		queue->first = aux;
		aux->next = NULL;
		queue->size++;
		return;
	}
	else
	{
		if (priority <= queue->first->priority)
		{
			aux->next = queue->first;
			queue->first = aux;
			queue->size++;
			return;
		}
		else
		{
			PQUEUENODE iterator = queue->first;

			while (iterator->next != NULL)
			{
				if (priority <= iterator->next->priority)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					queue->size++;
					return;
				}
				iterator = iterator->next;
			}

			if (iterator->next == NULL)
			{
				iterator->next = aux;
				aux->next = NULL;
				queue->size++;
				return;
			}
		}
	}
}

PTABLE BuildTable(PTREE tree)
{
	int k = 0;
	char code[MAXSIZE];

	PTABLE table = (PTABLE)malloc(sizeof(TABLE));
	table->first = table->last = NULL;

	TraverseTree(tree->root, table, k, code);

	PTLQNODE traversal = table->first;

	return table;
}

void TraverseTree(PTREENODE traversal, PTABLE table, int k, char * code)
{
	if (traversal->left==NULL && traversal->right==NULL)
	{
		code[k] = '\0';

		PTLQNODE aux = (PTLQNODE)malloc(sizeof(TLQNODE));

		aux->code = (char *)malloc(sizeof(char)*(strlen(code)+1));
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
	if (traversal->right != NULL)
	{
		code[k] = '1';
		TraverseTree(traversal->right, table, k+1, code);
	}
}

void Encode(PTABLE table, char * string_to_encode)
{
	PTLQNODE traversal;
	int i;


	printf("String to encode:\n%s\nEncodie:\n", string_to_encode);
	for (i=0; string_to_encode[i]!='\0'; i++)
	{
		traversal = table->first;

		while (traversal->symbol != string_to_encode[i])
			traversal = traversal->next;

		printf("%s", traversal->code);
	}
	printf("\n");
	return;
}

void Decode(PTREE tree, char * string_to_decode)
{
	PTREENODE traversal = tree->root;
	int i;

	printf("String to decode:\n%s\nEncodie:\n", string_to_decode);
	for (i=0; string_to_decode[i]!='\0'; i++)
	{
		if (traversal->left==NULL && traversal->right==NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}

		if (string_to_decode[i] == '0')
			traversal = traversal->left;
		else if (string_to_decode[i] == '1')
			traversal = traversal->right;
		else
		{
			printf("Decoding Error!\n");
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
