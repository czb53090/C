# include <stdio.h>
# include <stdlib.h>

void Get_Next(char * T, int * next);
int KMP(char * S, char * T, int pos);

int main(void)
{
	char S[255] = " absdfsssaaasd";
	char T[255] = " ssa";
	int i;

	S[0] = 13;
	T[0] = 3;

	i = KMP(S, T, 1);

	printf("%d\n", i);

	system("pause");
	return 0;
}

void Get_Next(char * T, int * next)
{
	int i, j;

	i = 1;
	j = 0;
	next[1] = 0;

	while (i < T[0])
	{
		if (0==j || T[i]==T[j])
		{
			i++;
			j++;

			if (T[i] != T[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
}

int KMP(char * S, char * T, int pos)
{
	int i, j;
	int next[255];

	Get_Next(T, next);
	
	i = pos;
	j = 1;

	while (j<=T[0] && i<=S[0])
	{
		if (0==j || S[i]==T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j > T[0])
		return i-T[0];
	else
		return 0;
}