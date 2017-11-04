# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define SQS_INIT_SIZE 20
# define SQSINCREMENT 10
# define BUFFERSIZE 10

typedef double ElemType;
typedef struct SqStack
{
	ElemType * pTop;
	ElemType * pBottom;
	int StackSize;
} SQS, * PSQS;

void InitSQS(PSQS pS);
int SQSLen(SQS S);
void Push(PSQS pS, ElemType val);
void Pop(PSQS pS, ElemType * pVal);
void Switch(PSQS pS, char e);

int main(void)
{
	SQS S, SQ;
	ElemType c, e;
	int i = 0;
	char a[BUFFERSIZE];
	double val1;
	
	InitSQS(&S);
	InitSQS(&SQ);

	printf("请输入中缀表达式：");
	c = getchar();
	while (c != '\n')
	{
		while (c>='0' && c<='9'|| c=='.')
		{
			
			printf("%c", (char)c);
			a[i++] = (char)c;
//			printf("a[%d] = %c\n", i, a[i-1]);
			a[i] = '\0';
			c = getchar();
			if (i >= BUFFERSIZE)
			{
				printf("ERROR!\n");
				exit(0);
			}
			if ((c<'0' || c>'9') && c!='.')
			{
				val1 = atof(a);
//				printf("val1 = %f\n", val1);
				Push(&SQ, val1);
				printf(" ");
				i = 0;
			}	
		}

		if (c == ')')
		{
			Pop(&S, &e);
			while (e != '(')
			{
				printf("%c ", (char)e);
				Switch(&SQ, (char)e);
				Pop(&S, &e);
			}
		}
		else if ('+'==c || '-'==c)
		{
			if (!SQSLen(S))
			{
				Push(&S, c);
			}
			else
			{
				do 
				{
					Pop(&S, &e);
					if (e == '(')
					{
						Push(&S, e);
					}
					else
					{
						printf("%c ", (char)e);
						Switch(&SQ, (char)e);
					}
				} while (SQSLen(S) && e!='(');
				Push(&S, c);
			}
		}
		else if ('*'==c || '/'==c || '('==c)
		{
			Push(&S, c);
		}
		else if (c == '\n')
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

	while (SQSLen(S))
	{
		Pop(&S, &e);
		printf("%c ", (char)e);
		Switch(&SQ, (char)e);	
	}
	printf("\n");
	Pop(&SQ, &val1);
	printf("最终计算结果是：%f\n", val1);
	
	system("pause");
	return 0;
}

int SQSLen(SQS S)
{
	return (S.pTop-S.pBottom);
}

void InitSQS(PSQS pS)
{
	pS->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_INIT_SIZE);
	if (NULL == pS->pBottom)
	{
		printf("分配空间失败！\n");
		system("pause");
		exit(0);
	}
	pS->pTop = pS->pBottom;
	pS->StackSize = SQS_INIT_SIZE;
}

void Push(PSQS pS, ElemType val)
{
	if ((pS->pTop)-(pS->pBottom) >= pS->StackSize)
	{
		pS->pBottom = (ElemType *)realloc(pS->pBottom, sizeof(ElemType)*(pS->StackSize+SQSINCREMENT));
		if (NULL == pS->pBottom)
		{
			printf("分配空间失败！\n");
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
	if (pS->pTop == pS->pBottom)
		return;
	*pVal = *(--(pS->pTop));
}

void Switch(PSQS pS, char e)
{
	double val1, val2;
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
};