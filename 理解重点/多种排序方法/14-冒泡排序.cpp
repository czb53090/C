# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[10] = {2, 3, -10, 3, -8, 1, 23, 4, -4, 0};
	int i, j, t;
	
	for(i=0; i<9; i++)
		for(j=0; j<9-i; j++)
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	
	for(i=0; i<10; i++)
		printf("%d ", a[i]);

	system("pause");
	return 0;
}