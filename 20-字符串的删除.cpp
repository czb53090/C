# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
	char a[100];
	int i, j, k, f;
	char c[20];

	gets_s(a);
	printf("请输入您想要删除的子字符串：");
	gets_s(c);
	
	k = strlen(c);
	do
	{
		j = 0;
		for (i=0; a[i]!='\0'; i++)
		{
			if (a[i] == c[j])
			{
				j++;
				if (j == 1)
					f = i;
				if(i != f+j-1)
					break;
			}
		}
		
		if(k == j)
		{
			for (i=k; a[f+k]!='\0'; i++,f++)
				a[f] = a[f+k];
			a[f] = '\0';
		}
		
		
	} while (k == j);
	printf("%s\n", a);
	
	system("pause");
	return 0;
}
