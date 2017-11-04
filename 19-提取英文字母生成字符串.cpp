# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	char a[100], b[100];
	char c;
	int i, j=0;

	gets_s(a);

	for (i=0; (c=a[i])!='\0'; i++)
	{
		if (c>64 && c<91 || c>96 && c<123)
		{
			b[j] = a[i];
			j++;
		}
	}

	b[j] = '\0';

	printf("%s\n", b);

	system("pause");
	return 0;
}
