/*
	2016��11��20��22:43:32
	Ŀ�ģ���һ���ַ�����������������Ϊһ��������һ�δ�ŵ�һά����a�в����
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
	ndigit = 0; //�������������ĸ���
	j = 0;

	for (i=0; *(pstr+i)!='\0'; i++)
	{
		if (*(pstr+i+1)!='\0' && *(pstr+i)>='0' && *(pstr+i)<='9')
				j++;
		else
		{
			if (*(pstr+i+1) == '\0')
			//���⵱ָ����ָ�����һ��Ϊ'\0'ʱ����ѭ������ͬ
			{
				i++; //i++��Ϊ���ü�����������
				j++;
			}
			if (j > 0)
			{
				digit = *(pstr+i-1) - 48; //�����str��ǰλ�õ�����ֵ
				for (k=1; k<j; k++)
				{
					e10 = 1;
					for (m=1; m<=k; m++)
					//ÿ�μ����ǰ��kλ������������e10�ټ���ԭ����digit
						e10 *= 10;
					digit += (*(pstr+i-1-k)-48) * e10;
				}
				*pa = digit; //����������a��ֵ��
				pa++; //��paָ����һ��Ԫ��
				ndigit++;
				j = 0;
				if (*(pstr+i+1) == '\0')
					i--; //���һ�����������ָ�iֵ��forѭ��i++������
						 //ѭ�������Ӵ˾�����
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