/*
	2016年11月20日22:43:32
	目的：将一段字符串中连续的数字作为一个整数，一次存放到一维数组a中并输出
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	char str[50], * pstr;
	int i, j, k, m, e10, digit, ndigit, a[10], * pa;
	printf("input a string:\n");
	gets_s(str);

	pstr = str; 
	pa = a;
	ndigit = 0; //计算所存整数的个数
	j = 0;

	for (i=0; *(pstr+i)!='\0'; i++)
	{
		if (*(pstr+i+1)!='\0' && *(pstr+i)>='0' && *(pstr+i)<='9')
				j++;
		else
		{
			if (*(pstr+i+1) == '\0')
			//避免当指针所指向的下一个为'\0'时跳出循环，上同
			{
				i++; //i++是为了让计算正常进行
				j++;
			}
			if (j > 0)
			{
				digit = *(pstr+i-1) - 48; //计算出str当前位置的整数值
				for (k=1; k<j; k++)
				{
					e10 = 1;
					for (m=1; m<=k; m++)
					//每次计算出前第k位的整数并乘以e10再加上原来的digit
						e10 *= 10;
					digit += (*(pstr+i-1-k)-48) * e10;
				}
				*pa = digit; //保存整数到a数值中
				pa++; //让pa指向下一个元素
				ndigit++;
				j = 0;
				if (*(pstr+i+1) == '\0')
					i--; //最后一个数计算过后恢复i值，for循环i++便跳出
						 //循环，不加此句会出错
			}
		}
	}

	printf("There are %d numbers in this line, they are:\n", ndigit);
	pa = a;
	for (i=0; i<ndigit; i++)
		printf("%d  ", *(pa+i));
	printf("\n");

	system("pause");
	return 0;
}