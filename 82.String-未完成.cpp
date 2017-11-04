#include <stido.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int status;


int main(void)
{
	char * string;
	int len;

	scanf("%d", &len);
	string = (char *)malloc(sizeof(char)*len);

	return 0;
}

status StrCopy(char * T, char * S)
{
	int i = 0;
	if (StrLenght(S))
	{
		while ((T[i]=S[i++]) == '\0');
		return true;
	}
	else
		return false;
}

status Status StrEmpty(char * S)
{
	return (S[0] == '\0');
}

status StrCompare(char * S, char * T)
{
		int i = 0;
		while (S[i] == T[i++])
			;
		return (S[i] - T[i]);
}

int StrLength(char * S)
{
	int i = 0;
	while (S[i] != '\0');

	return i;
}

status ClearString(char * S)
{
	if (StrLength(S))
	{
		S[0] = '\0';
		return true;
	}
	else
		return false;
}

status Concat(char * T, char * S1, char * S2)
{
	int i = 0;
	if (StrLenght(S1) && StrLenght(S2))
	{
		while ((T[i]=S1[i++]) != '\0');
		while ((T[i]=S2[i++]) != '\0');
		T[i] = '\0';
		return true;
	}
	else
		return false;
}

status SubString(char * Sub, char * S, int pos, int len)
{
	int i, j;
	char * p = S + pos;
	i = j = 0;

	if (pos>0 && pos <=StrLenght(S)+1)
	{	
		while (j < len)
		{
			if (p[j] == '\0')
				return false;
			Sub[i++] = p[j++];
		}
		Sub[i] = '\0';
		return true;
	}
	else
		return false;
}

status Index(char * S, char * T, int pos)
// ×Ö·û´®Æ¥Åä
{
	int tlen = StrLength(T);
	int slen = StrLength(S);
	int next[tlen];
	int i, j;
	i = pos;
	j = 0;
	
	if (StrLenght(S) && StrLenght(T))
	{
		GetNext(next, T);
	
		
	}
	else
		return -1;
}