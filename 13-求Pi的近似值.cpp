/*
	Ŀ�ģ���еĽ���ֵ
	����˼· (����)��
		1.��/4 �� 1 - 1/3 + 1/5 - 1/7 +������
		2.�� �� 22/7
		3.��^2/6 �� 1/1^2 + 1/2^2 + 1/3^2 + ������
		4.��/2 = 2*2/1*3 * 4*4/3*5 * 6*6/5*7 * ������ * (n-1)^2/n*(n+2)
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(void)
{
	//һ��һ�ַ���Ϊ��
	int sign = 1;
	double pi=0, i=1.0, tern=1.0;

	while(fabs(tern) >= 1e-8)
	{
		pi += tern;
		i += 2;
		sign = -sign;
		tern = sign/i;
	}
	printf("�� �� %.7lf", pi*4);


	system("pause");
	return 0;
}