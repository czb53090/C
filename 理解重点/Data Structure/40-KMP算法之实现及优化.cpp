# include <stdio.h>
# include <stdlib.h>

typedef char String;

void Get_Next(String T[], int * next);
int Index_TMP(String S[], String T[], int pos);

int main(void)
{
	String S[255] = " ababaaaba";
	String T[255] = " aaa";
	int i;
	S[0] = 9;
	T[0] = 3;
	
	printf("%d\n", Index_TMP(S, T, 0));

	system("pause");
	return 0;
}

void Get_Next(String T[], int * next)
{
	int j=0, i=1;
	next[1] = 0;

	while (i < T[0])
	{
		if (0==j || T[i]==T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}		
		}
		else
		{
			j = next[j];
		}
	}
}

//返回字串T在主串S第pos个字符之后的位置
//若不存在，则返回0
int Index_TMP(String S[], String T[], int pos)
{
	int i = pos;
	int j = 1;
	int next[255];

	Get_Next(T, next);

	while (i<=S[0] && j<=T[0])
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j > T[0])
	{
		return i-T[0];
	}
	else
	{
		return 0;
	}
}
