#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	long a = LONG_MAX;
	long long b = LLONG_MAX;
	printf("LONG_MAX = %ld\n", a);
	printf("LLONG_MAX = %lld\n", b);
	printf("sizeof(int) = %u\n", sizeof(int));
	printf("sizeof(long) = %u\n", sizeof(long));
	printf("sizeof(double) = %u\n", sizeof(double));
	
	return 0;
}
