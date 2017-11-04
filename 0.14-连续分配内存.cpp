# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

int main(void)
{
	while(1)
	{
		int * p = NULL;
		p = (int *)malloc(1024*1024*1024*1024);
	}

	system("pause");
	return 0;
}