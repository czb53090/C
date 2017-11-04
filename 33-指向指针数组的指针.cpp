# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[5] = {1,3,5,7,9};
	int * num[5] = {&a[0],&a[1],&a[2],&a[3],&a[4]};
	int ** p;
	int i;
	p = num;

	for (i=0; i<5; i++)
		printf("%5d", **p++);
	printf("\n");

	system("pause");
	return 0;
}