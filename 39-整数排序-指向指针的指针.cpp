# include <stdio.h>
# include <stdlib.h>

void sort(int ** p, int n);

int main(void)
{
	int * str[20], ** p, data[20];
	int i, j, n;

	for (i=0; i<20; i++)
		str[i] = &data[i];

	printf("input n:");
	scanf("%d", &n);
	printf("please input numbers:");
	for (i=0; i<n; i++)
		scanf("%d", str[i]);

	p = str;
	sort(p, n);

	printf("Now,the sequence is:\n");
	for (i=0; i<n; i++)
		printf("%d  ", *str[i]);
	printf("\n");

	system("pause");
	return 0;
}

void sort(int ** p, int n)
{
	int i, j;
	int * temp;
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++)
			if (**(p+i) > **(p+j))
			{
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
}