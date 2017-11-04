# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	unsigned int x, n;
	printf("input the number you want change(0~4294973495)[enter 'q' to quit!]:\n");
	//方法一
// 	while (scanf("%d", &x)==1)
// 	{
// 		for (n=~0x7fffffff; n!=0; n>>=1)
// 		{
// 			if ((n&x)!=0)
// 				printf("1");
// 			else
// 				printf("0");
// 		}
// 		printf("\n");
// 	}
	//方法二
	int i;
	unsigned int size = sizeof(int)*8;
	char a[100];
	while (scanf("%d", &x) == 1)
	{
		for(n=1,i=0; i<size; x>>=1,i++)
		{
			a[i] = (n&x) + '0';
		}
		for (i-=1; i>=0; i--)
			printf("%c", a[i]);
		printf("\n");
	}
	

	
	system("pause");
	return 0;
}