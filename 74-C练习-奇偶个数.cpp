# include <stdio.h>
# include <stdlib.h>

/*
	2016Äê12ÔÂ27ÈÕ16:56:30
*/

int main(void)
{
	int i=0, j=0, k=0;
	int a[20];

	scanf("%d", &a[k++]);
	while(a[k-1] != -1)
	{
		if (a[k-1]>=0 && a[k-1]<=100000)
		{
			if (a[k-1]%2)
				i++;
			else
				j++;
		}
		scanf("%d", &a[k++]);
	}


	printf("%d %d\n", i, j);
	
	system("pause");
	return 0;
}