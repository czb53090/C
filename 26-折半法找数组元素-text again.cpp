# include <stdio.h>
# include <stdlib.h>
# define N 15

int main(void)
{
	int i, number, top, bott, mid, loca, a[N], flag=1, sign;
	char c;

	printf("Please enter data:\n");
	scanf("%d", &a[0]);
	i = 1;
	while (i < N)
	{
		scanf("%d", &a[i]);
		if (a[i] <= a[i-1])
			printf("Please enter data again:\n");
		else
			i++;
	}

	for (i=0; i<N; i++)
		printf("%5d", a[i]);
	printf("\n");

	while (flag)
	{
		sign = loca = 0;
		top = 0;
		bott = N - 1;
		
		printf("input the number to find:");
		scanf("%d", &number);

		if (number<a[0] || number>a[N-1])
			loca = -1;
		while ((!sign) && (top<=bott))
		{
			mid = (top+bott) / 2;
			if (number == a[mid])
			{
				loca = mid;
				printf("Has found %d,its position is %d.\n", number, loca+1);
				sign = 1;
			}
			else if (number < a[mid])
				bott = mid - 1;
			else
				top = mid + 1;
		}

		if((!sign) || loca==-1)
			printf("cannot found %d.", number);

		printf("continue or not(Y/N):");
		scanf(" %c", &c);
		if (c=='n' || c=='N')
			flag = 0;
	}

	system("pause");
	return 0;
}