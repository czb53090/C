#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a, b;
	char dntion,c;
	do{
		
		scanf("%ld %c %ld",&a, &dntion, &b);
		if (dntion == '+'){
			printf(" = %d\n",a+b);
		} else if (dntion == '-'){
			printf(" = %d\n",a-b);
		} else if (dntion == '*'){
			printf(" = %d\n",a*b);
		} else if (dntion == '/'){
			if (b == 0){
				printf("��������Ϊ��\n");
			} else {
				printf(" = %d\n",a/b);
			}
		} else {
			printf("���Ŵ���\n"); 
		} 
		printf("�������㣿����: n\n");
		c = getche();
	} while(c == 110);
	
    system("pause");
	return 0;
}
