/*
	2017年1月12日10:35:45  
	2017年1月12日11:21:16
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
} QUEUENODE,  * PQUEUENODE;
typedef struct Queue
{
	PQUEUENODE first;
	unsigned int size;
} QUEUE, * PQUEUE;
typedef struct TableNode
{
	char symbol;
	char * code;
	struct TableNode * next;
} TABLENODE, * PTABLENODE;
typedef struct Table
{
	PTABLENODE first, last;
} TABLE, * PTABLE;

PTREE Build_Huffmantree(char * string);
void Init_Queue(PQUEUE * queue);
void Add_Queue(PQUEUE queue, PTREENODE val, unsigned int priority);
PTREENODE Get_Queue_TreeNode(PQUEUE queue);
PTABLE Build_CodeTable(PTREE tree);
void Traverse_Tree(PTABLE table, PTREENODE traversal, unsigned int k, char * code);
void Encode(PTABLE table, char * string_to_encode);
void Decode(PTREE tree, char * string_to_decode);

int main(void)
{
	PTREE codetree = Build_Huffmantree("Keep fighting!");
	
	PTABLE codetable  = Build_CodeTable(codetree);

	Encode(codetable, "Keep fighting!");
	
	Decode(codetree, "01010100101010101");
	
	system("pause");
	return 0;
}

PTREE Build_Huffmantree(char * string)
{
	int i, j, k;

	int * probability = (int *)malloc(sizeof(int)*MAXSIZE);
	if (NULL == probability)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}

	for (i=0; i<MAXSIZE; i++)
		probability[i] = 0;

	for (j=0; string[j]!='\0'; j++)
		probability[(unsigned char)string[j]]++;
	
	PQUEUE queue;
	Init_Queue(&queue);

	for (k=0; k<MAXSIZE; k++)
		if (probability[k] != 0)
		{
			PTREENODE aux  = (PTREENODE)malloc(sizeof(TREENODE));
			if (NULL == aux)
			{
				printf("ERROR!\n");
				system("pause");
				exit(0);
			}
			aux->left = aux->right = NULL;
			aux->symbol = k;

			Add_Queue(queue, aux, probability[k]);
		}

	free(probability);

	while (queue->size != 1)
	{
		unsigned int priority = queue->first->priority + queue->first->next->priority;

		PTREENODE left = Get_Queue_TreeNode(queue);
		PTREENODE right = Get_Queue_TreeNode(queue);

		PTREENODE aux = (PTREENODE)malloc(sizeof(TREENODE));
		if (NULL == aux)
		{
			printf("ERROR!\n");
			system("pause");
			exit(0);
		}

		aux->left = left;
		aux->right = right;

		Add_Queue(queue, aux, priority);
	}

	

	PTREE tree = (PTREE)malloc(sizeof(TREE));
	if (NULL == tree)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}

	tree->root = Get_Queue_TreeNode(queue);

	return tree;
}

void Init_Queue(PQUEUE * queue)
{
	*queue = (PQUEUE)malloc(sizeof(QUEUE));
	if (NULL == *queue)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	(*queue)->first = NULL;
	(*queue)->size = 0;

	return;
}

void Add_Queue(PQUEUE queue, PTREENODE val, unsigned int priority)
{
	if (queue->size == MAXSIZE)
	{
		printf("Queue is full!\n");
		system("pause");
		return;
	}

	PQUEUENODE aux = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	if (NULL == aux)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}

	aux->val = val;
	aux->priority = priority;

	if (0==queue->size || NULL==queue->first)
	{
		aux->next = NULL;
		queue->first = aux;
		queue->size = 1;
		return;
	}
	else
	{
		if (queue->first->priority >= priority)
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
				aux->next = NULL;
				iterator->next = aux;
				queue->size++;
				return;
			}
		}
	}
}

PTREENODE Get_Queue_TreeNode(PQUEUE queue)
{
	PTREENODE val = NULL;

	if (queue->size > 0)
	{
		val = queue->first->val;
		queue->first = queue->first->next;
		queue->size--;
	}
	else
		printf("Queue is Empty!\n");

	return val;
}

PTABLE Build_CodeTable(PTREE tree)
{
	int k = 0;
	char code[MAXSIZE];
	PTABLE table = (PTABLE)malloc(sizeof(TABLE));
	if (NULL == table)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	table->first = table->last = NULL;

	Traverse_Tree(table, tree->root, k, code);

	return table;
}

void Traverse_Tree(PTABLE table, PTREENODE traversal, unsigned int k, char * code)
{
	if (NULL==traversal->left && NULL==traversal->right)
	{
		code[k] = '\0';

		PTABLENODE aux = (PTABLENODE)malloc(sizeof(TABLENODE));
		aux->code = (char *)malloc(sizeof(char)*(strlen(code)+1));
		if (NULL==aux || NULL==aux->code)
		{ 
			printf("ERROR!\n");
			system("pause");
			exit(0);
		}
		
		strcpy(aux->code, code);
		aux->symbol = traversal->symbol;
		aux->next = NULL;
		
		if (NULL == table->first)
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
		Traverse_Tree(table, traversal->left, k+1, code);
	}
	
	if (traversal->right != NULL)
	{
		code[k] = '1';
		Traverse_Tree(table, traversal->right, k+1, code);
	}
	
	return;
}

void Encode(PTABLE table, char * string_to_encode)
{
	PTABLENODE traversal;
	int i;

	printf("String to encode:\n%s\nEncode:\n", string_to_encode);

	for (i=0; string_to_encode[i]!='\0'; i++)
	{
		traversal = table->first;
		
		while (traversal->symbol != string_to_encode[i])
		{
			if (traversal == NULL)
			{
				printf("Error,%c is not found!\n", string_to_encode[i]);
				system("pause");
				return;
			}
			traversal = traversal->next;
		}
			
		printf("%s", traversal->code);
	}
	
	printf("\n\n");

	return;
}

void Decode(PTREE tree, char * string_to_decode)
{
	PTREENODE traversal = tree->root;
	int i;

	printf("String to decode:\n%s\nDecode:\n", string_to_decode);

	for (i=0; string_to_decode[i]!='\0'; i++)
	{
		if (NULL==traversal->left && NULL==traversal->right)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}

		if ('0' == string_to_decode[i])
			traversal = traversal->left;
		else if ('1' == string_to_decode[i])
			traversal = traversal->right;
		else
		{
			printf("Decoding error!\n");
			system("pause");
			return;
		}
	}

	if (NULL==traversal->left && NULL==traversal->right)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}
	printf("\n");

	return;
}

