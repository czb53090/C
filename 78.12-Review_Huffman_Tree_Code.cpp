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
} TREE, * PTREE;
typedef struct QueueNode
{
	PTREENODE tree_node;
	unsigned int priority;
	struct QueueNode * next;
} QUEUENODE, * PQUEUENODE;
typedef struct Queue
{
	unsigned int size;
	PQUEUENODE first;
} QUEUE, * PQUEUE;
typedef struct TableNode
{
	char symbol;
	char * code;
	struct TableNode * next;
} TABLENODE, * PTABLENODE;
typedef struct Table
{
	PTABLENODE first;
	PTABLENODE last;
} TABLE, * PTABLE;

PTREE Build_Tree(char * S);
void Init_Queue(PQUEUE * pQ);
void Add_To_Queue(PQUEUE pQ, PTREENODE tree_node, unsigned int priority);
PTREENODE Get_QNode_TNode(PQUEUE pQ);
PTABLE Build_Table(PTREE tree);
void Traverse_Tree(PTREENODE tree_node, PTABLE table, int k, char * code);
void Encode(PTABLE table, char * S);
void Decode(PTREE tree, char * S);

int main(void)
{
	PTREE tree;
	PTABLE table;

	tree = Build_Tree("Tomorrow is another day!");
	table = Build_Table(tree);

	Encode(table, "Tomorrow is another day!");
	Decode(tree, "111000011011000110110010111100110");

	system("pause");
	return 0;
}

PTREE Build_Tree(char * S)
{
	int  * probability;
	int i;

	probability = (int *)malloc(sizeof(int)*255);
	for (i=0; i<255; i++)
		probability[i] = 0;

	for (i=0; S[i]!='\0'; i++)
		probability[(unsigned char)S[i]]++;
	
	PQUEUE pQ;
	Init_Queue(&pQ);

	for (i=0; i<255; i++)
		if (probability[i] != 0)
		{
			PTREENODE tree_node = (PTREENODE)malloc(sizeof(TREENODE));
			tree_node->left = tree_node->right = NULL;
			tree_node->symbol = (char)i;

			Add_To_Queue(pQ, tree_node, probability[i]);
		}

	free(probability);

	while (pQ->size != 1)
	{
		unsigned int priority = pQ->first->priority;
		priority += pQ->first->next->priority;

		PTREENODE left = Get_QNode_TNode(pQ);
		PTREENODE right = Get_QNode_TNode(pQ);

		PTREENODE new_tree_node = (PTREENODE)malloc(sizeof(TREENODE));
		new_tree_node->left = left;
		new_tree_node->right = right;

		Add_To_Queue(pQ, new_tree_node, priority);
	}

	PTREE tree = (PTREE)malloc(sizeof(TREE));
	tree->root = Get_QNode_TNode(pQ);

	return tree;
}
void Init_Queue(PQUEUE * pQ)
{
	*pQ = (PQUEUE)malloc(sizeof(QUEUE));

	(*pQ)->first = NULL;
	(*pQ)->size = 0;

	return;
}

void Add_To_Queue(PQUEUE pQ, PTREENODE tree_node, unsigned int priority)
{
	PQUEUENODE queue_node = (PQUEUENODE)malloc(sizeof(QUEUENODE));

	if (pQ->size == 255)
	{
		printf("\nQueue is full!\n");
		system("pause");
		return;
	}

	queue_node->tree_node = tree_node;
	queue_node->priority = priority;

	pQ->size++;
	if (!pQ->first || !pQ->size)
	{
		pQ->first = queue_node;
		queue_node->next = NULL;
	}
	else
	{
		if (priority <= pQ->first->priority)
		{
			queue_node->next = pQ->first;
			pQ->first = queue_node;
		}
		else
		{
			PQUEUENODE iterator;

			iterator=pQ->first;
			while (iterator->next != NULL)
			{
				if (priority <= iterator->next->priority)
				{
					queue_node->next = iterator->next;
					iterator->next = queue_node;
					break;
				}

				iterator=iterator->next;
			}
			if (iterator->next == NULL)
			{
				queue_node->next = NULL;
				iterator->next = queue_node;
			}
		}
	}
	return;
}

PTREENODE Get_QNode_TNode(PQUEUE pQ)
{
	PTREENODE tree_node;

	tree_node = NULL;
	
	if (pQ->size > 0)
	{
		tree_node = pQ->first->tree_node;
		pQ->first = pQ->first->next;
		pQ->size--;
	}
	else
		printf("\nQueue is empty!\n");

	return tree_node;
}

PTABLE Build_Table(PTREE tree)
{
	char code[255];
	int k;

	PTABLE table = (PTABLE)malloc(sizeof(TABLE));
	table->first = table->last = NULL;

	k = 0;
	Traverse_Tree(tree->root, table, k, code);

	return table;
}

void Traverse_Tree(PTREENODE tree_node, PTABLE table, int k, char * code)
{
	if (!tree_node->left && !tree_node->right)
	{
		PTABLENODE table_node = (PTABLENODE)malloc(sizeof(TABLENODE));
	
		table_node->symbol = tree_node->symbol;
		table_node->next = NULL;

		code[k] = '\0';
		table_node->code = (char *)malloc(sizeof(char)*(strlen(code)+1));
		strcpy(table_node->code, code);


		if (!table->first)
		{
			table->first = table->last = table_node;
		}
		else
		{
			table->last->next = table_node;
			table->last = table_node;
		}
	}
	else
	{
		if (tree_node->left != NULL)
		{
			code[k] = '0';
			Traverse_Tree(tree_node->left, table, k+1, code);
		}
		if (tree_node->right != NULL)
		{
			code[k] = '1';
			Traverse_Tree(tree_node->right, table, k+1, code);
		}
	}
}

void Encode(PTABLE table, char * S)
{
	int i;
	PTABLENODE iterator;

	printf("\nEncode_String:\n%s\nEncoding:\n", S);
	for (i=0; S[i]!='\0'; i++)
	{
		iterator = table->first;

		while (iterator->symbol!=S[i] && iterator)
			iterator = iterator->next;	
		
		if (!iterator)
		{
			printf("Encode error!\n");
			system("pause");
			return;
		}
		printf("%s", iterator->code);
	}
	printf("\n");

	return;
}

void Decode(PTREE tree, char * S)
{
	int i;
	PTREENODE traversal = tree->root;

	printf("\nDecode_String:\n%s\nDecoding:\n", S);
	for (i=0; S[i]!='\0'; i++)
	{
		if (!traversal->left & !traversal->right)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}

		if ('0' == S[i])
			traversal = traversal->left;
		else if ('1' == S[i])
			traversal = traversal->right;
		else
		{
			printf("Decode Error!\n");
			system("pause");
			return;
		}
	}

	if (!traversal->left & !traversal->right)
	{
		printf("%c", traversal->symbol);
		traversal = tree->root;
	}
	printf("\n");

	return;
}