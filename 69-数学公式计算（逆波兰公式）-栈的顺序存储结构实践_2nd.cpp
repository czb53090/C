# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define SQS_ININ_SIZE 20
# define SQSINCREMENT 10
# define BUFFERSIZE 10

/*
	2016年12月18日23:53:29
*/

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
	SQS S1 ,S2;
	char a[BUFFERSIZE];
	ElemType c, e, val;
	int i = 0;

	InitSQS(&S1);
	InitSQS(&S2);

	printf("输入数学公式：");

	c = getchar();
	while (c != '\n')
	{
		while (c>='0' && c<='9' || c=='.')
		{
			printf("%c", (char)c);
			a[i++] = (char)c;
			a[i] = '\0';
			
			if (i >= BUFFERSIZE)
			{
				printf("错误，输入的单个数值的长度过大！\n");
				system("pause");
				return -1;
			}
			c = getchar();
			if ((c<'0' || c>'9') && c!='.')
			{
				printf(" ");
				val = atof(a);
				Push(&S2, val);
				i = 0;
			}
		}

		if (')' == c)
		{
			Pop(&S1, &e);
			while (e != '(')
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
					if (e == '(')
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
		else if ('\n' == c)
		{
			break;
		}
		else if (' ' == c)
		{
			;
		}
		else
		{
			printf("输入的格式有误！\n");
			system("pause");
			return -1;
		}

		c = getchar();
	}

	while (SQSLen(S1))
	{
		Pop(&S1, &e);
		printf("%c ", (char)e);
		Switch(&S2, (char)e);
	}
	printf("\n");
	Pop(&S2, &val);
	printf("最终的计算结果是：%f\n", val);

	system("pause");
	return 0;
}

void InitSQS(PSQS pS)
{
	pS->pBottom = (ElemType *)malloc(sizeof(ElemType)*SQS_ININ_SIZE);
	if (NULL == pS->pBottom)
	{
		printf("为栈分配空间失败！\n");
		system("pause");
		exit(0);
	}
	pS->pTop = pS->pBottom;
	pS->StackSize = SQS_ININ_SIZE;
}

int SQSLen(SQS S)
{
	return (S.pTop-S.pBottom);
}

void Push(PSQS pS, ElemType val)
{
	if (pS->pTop-pS->pBottom >= pS->StackSize)
	{
		pS->pBottom = (ElemType *)realloc(pS->pBottom, sizeof(ElemType)*(pS->StackSize+SQSINCREMENT));
		if (NULL == pS->pBottom)
		{
			printf("为栈分配空间失败！\n");
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
		return ;
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
}
