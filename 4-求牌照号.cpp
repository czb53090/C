#include <stdio.h>
#include <stdlib.h>
/*(1)牌照号是一个四位数
  (2)前后两位数相同
  (3)这个数是一个整数的平方  */ 
int main(int argc, char const *argv[])
{
	int a,b,c,d,i,n;
	for (i=1000; i<=9999&i>=1000; i++) {
		a = i/1000;
		b = i%1000/100;
		c = i%100/10;
		d = i%10;
		if (a==b && c==d) {
			for (n=2; n<=142; n++){
				if (i== n*n){
					printf("%d",i);
					break;
				}
			}		
		}
	}
	printf("\n");
    system("pause");
	return 0;
}
