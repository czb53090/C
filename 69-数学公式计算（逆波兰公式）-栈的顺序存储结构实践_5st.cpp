/*
	2016年12月27日20:10:25
	2016年12月27日20:59:15
	耗时：48分钟50秒
*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define SQS_INIT_SIZE 30
# define SQSINCREMENT 20
# define BUFFERSIZE 10

typedef double ElemType;
typedef struct SqStack
{
	ElemType * pTop;
	ElemType * pBottom;
	int StackSize;
}SQS, * PSQS;

void Init_SQS(PSQS * pS);
int SQSLen(SQS S);
void Push(PSQS pS, ElemType val);
void Pop(PSQS pS, ElemType * pVal);
void Switch(PSQS pS, char e);

int main(void)
{
	PSQS S1, S2;
	ElemType c, e;
	char a[BUFFERSIZE];
	int i = 0;

	S1 = S2 = NULL;

	Init_SQS(&S1);
	Init_SQS(&S2);

	c = getchar();
	while ('\n' != c)
	{
		while ((c>='0' && c<='9') || '.'==c)
		{
			a[i++] = (char)c;
			a[i] = '\0';
			if (i >= BUFFERSIZE)
			{
				printf("ERROR!");
				system("pause");
				return -1;
			}
			c = getchar();
			if (c>'9' || c<'0')
			{
				e = atof(a);
				printf("%d ", (int)e);
				Push(S2, e);
				i = 0;
			}
		}

		if (')' == c)
		{
			Pop(S1, &e);
			while ('(' != e)
			{
				printf("%c ", (char)e);
				Switch(S2, (char)e);
				Pop(S1, &e);
			}
		}
		else if ('+'==c || '-'==c)
		{
			if (!SQSLen(*S1))
				Push(S1, c);
			else
			{
				do 
				{
					Pop(S1, &e);
					if (e == '(')
					{
						Push(S1, e);
					}
					else
					{
						printf("%c ", (char)e);
						Switch(S2, (char)e);
					}
				} while (SQSLen(*S1) && e!='(');
				Push(S1, c);
			}
		}
		else if ('*'==c || '/'==c || '('==c)
			Push(S1, c);
		else if ('\n' == c)
			break;
		else if (' ' == c)
			;
		else
		{
			printf("Input ERROE!");
			system("pause");
			return -1;
		}

		c = getchar();
	}

	while (SQSLen(*S1))
	{
		Pop(S1, &e);
		printf("%c ", (char)e);
		Switch(S2, (char)e);
	}

	printf("\n逆波兰表达式计算结果是：");
	Pop(S2, &e);
	printf("%f\n", e);

	free(S1);
	free(S2);

	system("pause");
	return 0;
}

void Init_SQS(PSQS * pS)
{
	(*pS) = (PSQS)malloc(sizeof(SQS));
	if (NULL == *pS)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	(*pS)->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == (*pS)->pBottom)
	{
		printf("ERROR!\n");
		system("pause");
		exit(0);
	}
	(*pS)->pTop = (*pS)->pBottom;
	(*pS)->StackSize = SQS_INIT_SIZE;
}

int SQSLen(SQS S)
{
	return (S.pTop-S.pBottom);
}

void Push(PSQS pS, ElemType val)
{
	if ((pS->pTop-pS->pBottom) >= pS->StackSize)
	{
		pS->pBottom = (ElemType *)realloc(pS->pBottom, sizeof(ElemType)*(pS->StackSize+SQSINCREMENT));
		if (NULL == pS->pBottom)
		{
			printf("ERROR!\n");
			system("pause");
			exit(0);
		}
		pS->pTop = pS->pBottom + pS->StackSize;
		pS->StackSize += SQSINCREMENT;
	}
	*((pS->pTop)++) = val; 
}

void Pop(PSQS pS, ElemType * pVal)
{
	*pVal = *(--(pS->pTop));
}

void Switch(PSQS pS, char e)
{
	ElemType val1, val2;

	switch (e)
	{
	case '+':
		Pop(pS, &val1);
		Pop(pS, &val2);
		Push(pS, val2+val1);
		break;
	case '-':
		Pop(pS, &val1);
		Pop(pS, &val2);
		Push(pS, val2-val1);
		break;
	case '*':
		Pop(pS, &val1);
		Pop(pS, &val2);
		Push(pS, val2*val1);
		break;
	case '/':
		Pop(pS, &val1);
		Pop(pS, &val2);
		Push(pS, val2/val1);
		break;
	}
}