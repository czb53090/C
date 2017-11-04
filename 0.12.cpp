#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a=1,b=3,c=5,d=4,x;
	if(a<b)
		if(c<d) x=1;
		else
			if(a<c)
				if(b<d) x=2;
				else x=3;
			else x=6;
		else x=7;
		printf ("%d", x);
		 
	printf("\n");
    system("pause");
	return 0;
}
