#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a, b, c;
	double s,S;
	scanf("%d %d %d",&a, &b, &c);
	s = (a+b+c)/2.0;
	//result = sqrt(x);//result*result = x
	S = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("S=%f\n", S);
    system("pause");
	return 0;
}
