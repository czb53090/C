#include <stdio.h>
#include <stdlib.h>
/*(1)���պ���һ����λ��
  (2)ǰ����λ����ͬ
  (3)�������һ��������ƽ��  */ 
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
