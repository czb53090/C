# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define SQS_INIT_SIZE 20
# define SQSINCREMENT 10
# define BUFFERSIZE 10

typedef double ElemType;
typedef struct SqStack
{
	ElemType * pBottom;
	ElemType * pTop;
	int StackSize;
}SQS, * PSQS;

void InitSQS(PSQS pS);
int SQSLen(SQS S);
void Push(PSQS pS, ElemType val);
void Pop(PSQS pS, ElemType * pVal);
void Switch(PSQS pS, char e);

int main(void)
{
	ElemType c, e;
	char a[BUFFERSIZE];
	SQS S1, S2; 
	int i = 0;

	InitSQS(&S1);
	InitSQS(&S2);

	printf("输入数学公式：");

	c = getchar();
	while (c != '\n')
	{
		while (c>='0' && c<='9' || c=='.')
		{
			a[i++] = (char)c;
			a[i] = '\0';
			printf("%c", (char)c);

			if (i >= BUFFERSIZE)
			{
				printf("错误，输入的单个数值的长度过大！\n");
				system("pause");
				return -1;
			}
			c = getchar();
			if ((c<'0' || c>'9') && c!='.')
			{
				e = atof(a);
				Push(&S2, e);
				printf(" ");
				i = 0;
			}

		}

		if (')' == c)
		{
			Pop(&S1, &e);
			while (c != '(')
			{
				printf("%c ", (char)e);
				Switch(&S2, (char)e);
				Pop(&S1, &e);
			}
		}
		else if ('+'==c || '-'==c)
		{
			if (!SQSLen(S1))
			{
				Push(&S1, c);
			}
			else
			{
				do 
				{
					Pop(&S1, &e);
					if ('(' == e)
					{
						Push(&S1, e);
					} 
					else
					{
						printf("%c ", (char)e);
						Switch(&S2, (char)e);
					}
				} while (SQSLen(S1) && e!='(');
				Push(&S1, c);
			}
		}
		else if ('*'==c || '/'==c || '('==c)
		{
			Push(&S1, c);
		}
		else if (' ' == c)
		{
			;
		}
		else if ('\n' == c)
		{
			break;
		}
		else
		{
			printf("输入格式有误！\n");
			system("pause");
			return -1;
		}

		c = getchar();
	}

	while (SQSLen(S1))
	{
		Pop(&S1, &e);
		Switch(&S2, (char)e);
		printf("%c ", (char)e);
	}
	printf("\n最终结算结果是：");

	Pop(&S2, &e);
	printf("%f", e);

	system("pause");
	return 0;
}

void InitSQS(PSQS pS)
{
	pS->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == pS->pBottom)
	{
		printf("栈分配空间！\n");
		system("pause");
		exit(0);
	}
	pS->pTop = pS->pBottom;
	pS->StackSize = SQS_INIT_SIZE;
}

int SQSLen(SQS S)
{
	return (S.pTop-S.pBottom);
}

void Push(PSQS pS, ElemType val)
{
	if ((pS->pTop-pS->pBottom) >= pS->StackSize)
	{
		pS->pBottom = (ElemType *)realloc(pS->pBottom, sizeof(ElemType)*(SQSINCREMENT+pS->StackSize));
		if (NULL == pS->pBottom)
		{
			printf("栈分配空间！\n");
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
	if (pS->pBottom == pS->pTop)
		return ;
	*pVal = *(--(pS->pTop));
}
void Switch(PSQS pS, char e)
{
	ElemType val1, val2;

	switch(e)
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
