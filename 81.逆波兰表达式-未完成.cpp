#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100
#define MAXNUMINTSIZE 9
#define Is_numeric(x) ((x>='0' && x<='9') || x=='.')
typedef double ElemType;

void Count(ElemType * stack, int * top, char e);

int main(void)
{
	ElemType * stack1 = (ElemType *)malloc(sizeof(ElemType)*STACKSIZE);
	char * stack2 = (char *)malloc(sizeof(char)*STACKSIZE);
	int top1=0, top2=0;
	char c, e;
	double number;
	int i = 0;
	char strnum[MAXNUMINTSIZE];

	c = getchar();
	while ('\n' != c)
	{
		while (Is_numeric(c))
		{
			strnum[i++] = c;

			if (i >= MAXNUMINTSIZE)
			{
				printf("Error,the size if too big!");
				system("pause");
				exit(0);
			}

			c = getchar();

			if (!Is_numeric(c))
			{
				strnum[i] = '\0';
				number = atof(strnum);
				stack1[top1++] = number;
				printf("%.2f ", number);
				i = 0;
			}
		}

		if (c=='*' || c=='/' || c=='(')
		{
			stack2[top2++] = c;
		}
		else if ('+'==c || '-'==c)
		{
			if (top2)
			{
				do
				{
					e = stack2[--top2];

					if (e == '(')
						stack2[top2++] = e;
					else
					{
						Count(stack1, &top1, e);
						printf("%c ", e);
					}
				} while (top2 && e!='(');
			}

			stack2[top2++] = c;
		}
		else if (c == ')')
		{
			e = stack2[--top2];
			while ('(' != e)
			{
				printf("%c ", e);
				Count(stack1, &top1, e);
				e = stack2[--top2];
			} 
		}
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

	while (top2)
	{
		e = stack2[--top2];
		printf("%c ", e);
		Count(stack1, &top1, e);
	}

	printf("\n逆波兰表达式计算结果是：");
	number = stack1[--top1];
	printf("%.2f\n", number);

	free(stack1);
	free(stack2);

	system("pause");
	return 0;
}

void Count(ElemType * stack, int * top, char e)
{
	ElemType val1, val2;

	switch (e)
	{
	case '+':
		val1 = stack[--*top];
		val2 = stack[--*top];
		stack[(*top)++] = val2+val1;
		break;
	case '-':
		val1 = stack[--*top];
		val2 = stack[--*top];
		stack[(*top)++] = val2-val1;
		break;
	case '*':
		val1 = stack[--*top];
		val2 = stack[--*top];
		stack[(*top)++] = val2*val1;
		break;
	case '/':
		val1 = stack[--*top];
		val2 = stack[--*top];
		stack[(*top)++] = val2/val1;
		break;
	}
}