#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x,y;
	x = y = 6;
	if(++x<y++){//++�в������� 
		printf("%d", x++);
	} else {
		printf("%d", y++);
	}
	printf("\n");
    system("pause");
	return 0;
}
