# include <stdio.h>
# include <stdlib.h>

# define NULLKEY -65535
# define MAXSIZE 12

typedef struct Hash
{
	int count;
	int * HashTable;
} HASH, * PHASH;

void Init_Hash(PHASH * H);
void Create_Hash_Table(PHASH H);
void Search_Hash(PHASH H, int key);
int Hash(int key);

int main(void)
{
	PHASH H;
	
	Init_Hash(&H);
	Create_Hash_Table(H);

	for (int i=0; i<H->count; i++)
		printf("%d ", H->HashTable[i]);
	printf("\n");

	Search_Hash(H, 12);


	system("pause");
	return 0;
}

void Init_Hash(PHASH * H)
{
	*H = (PHASH)malloc(sizeof(HASH));
	(*H)->count = MAXSIZE;
	(*H)->HashTable = (int *)malloc(sizeof(int)*MAXSIZE);
	for (int i=0; i<MAXSIZE; i++)
		(*H)->HashTable[i] = NULLKEY;
}

void Create_Hash_Table(PHASH H)
{
	int i, key, addr;

	for (i=0; i<H->count; i++)
	{
		scanf("%d", &key);
		addr = Hash(key);
		while (H->HashTable[addr]!=NULLKEY)
		{
			addr = (addr+1) % MAXSIZE;
			if (addr == Hash(key))
			{
				printf("Insert %d Fail!\n", key);
				system("pause");
				return;
			}
		}
		
		H->HashTable[addr] = key;
	}
}

void Search_Hash(PHASH H, int key)
{
	int addr;

	addr = Hash(key);
	
	while (H->HashTable[addr]!=key)
	{
		addr = (addr+1) % MAXSIZE;
		if (addr == Hash(key))
		{
			printf("No found!\n");
			return;
		}
	}

	printf("Is found,the location is %d\n", addr+1);

	return;
}

int Hash(int key)
{	
	return key%MAXSIZE;
}
