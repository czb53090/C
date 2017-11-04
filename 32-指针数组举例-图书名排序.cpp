# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void sort(char * name[], int n);
void print(char * name[], int n);

int main(void)
{
	char * name[5] = {"Follow me","BASIC","Greak Wall","FORTRAN","Computer design"};
	int n = 5;

	sort(name, n);
	print(name, n);

	system("pause");
	return 0;
}

void sort(char * name[], int n)
{
	int i, j, k;
	char * temp;

	for (i=0; i<n; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
			if (strcmp(name[k],name[j]) > 0)
				k = j;
		if (k != i)
		{
			temp = name[i];
			name[i] = name[k];
			name[k] = temp;
		}
	}
}

void print(char * name[], int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("%s\n", name[i]);

}