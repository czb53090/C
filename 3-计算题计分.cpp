#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int score= 0;
	int a,b,sum,i;
	for (i=1; i<=5; i++){
		srand((unsigned)time(NULL));
		a=rand();
		b=rand();
		printf("%d+%d=", a, b);
		scanf("%d",&sum);
		if (sum == a+b){
			score += 20;
		}
	}
	printf("×Ü¼Æ£º%d·Ö\n",score);
	system("pause");
	return 0;
}
