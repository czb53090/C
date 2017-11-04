#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x=1,y=2,z=3,m=1;
	if(!x) m--;//!x表示x为零的时候才执行 
	else if(!y) m=2;
	else if(!z);
	else m=3;
	printf("%d", m);//0 1 2 3 ? 
	printf("\n");
    system("pause");
	return 0;
}
