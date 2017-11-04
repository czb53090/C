# include <stdio.h>
# include <stdlib.h>

# define FIBONACCI_SIZE 10
# define Array_SIZE 10

typedef int Status;

void Fibonacci_Array(int * f);
Status Fibonacci_Search(int * a, int n, int key);

int main(void)
{
	int a[22] = {1,3,5,6,8,10,14,16,20,21};
	int i;

	if (-1 != (i=Fibonacci_Search(a, Array_SIZE, 1)))
		printf("Is found,the location is %d.\n", i+1);
	else
		printf("Cannot found!\n");

	system("pause");
	return 0;
}

void Fibonacci_Array(int * f)
{
	int i;

	f[0] = f[1] = 1;

	for (i=2; i<FIBONACCI_SIZE; i++)
		f[i] = f[i-1] + f[i-2];
}

Status Fibonacci_Search(int * a, int n, int key)
{
	int low, high, mid, i, k;
	int f[FIBONACCI_SIZE];

	Fibonacci_Array(f);

	k = 0;
	while (n > f[k]-1)
		k++;

	high = n-1;

	for (i=n; i<f[k]-1; i++)
		a[i] = a[high];

	low = 0;
	while (low <= high)
	{
		mid = low + f[k-1]-1;

		if (key < a[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid < n)
				return mid;
			else
				return n-1;
		}
	}
	return -1;
}

