# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int x, j, t, num = 0, sum = 1;

	printf("������һ�����֣�");
	scanf("%d", &x);

	t = x;
	while (t > 10)
	{
		t /= 10;
		sum *= 10; //���10��n-1�� ��λ��
	}
	printf("sum = %d\n", sum);

	while (x > 0)
	{
		j = x / sum;

		printf("j = %d  ", j);
		if (j%2 == 1)
		{
			num = num*10 + j;
		}

		x = x % sum;
		sum /= 10;
		
		printf("x = %d   ", x);
		printf("sum = %d\n\n", sum);
	}
	printf("num = %d\n", num);

	system("pause");
	return 0;
}
/*��Vc++6.0�е��������ǣ�
--------------------------
������һ�����֣�1234567
sum = 1000000
j = 1  x = 234567   sum = 100000

j = 2  x = 34567   sum = 10000
  
j = 3  x = 4567   sum = 1000
	
j = 4  x = 567   sum = 100
	  
j = 5  x = 67   sum = 10
		
j = 6  x = 7   sum = 1
		  
j = 7  x = 0   sum = 0
			
num = 1357
--------------------------
    �ܽ᣺����һ������x�����������λ��n��������sumΪ10��n-1���ݣ���ѭ����ֱ��x<=0��
	ÿ��ѭ����x/sum�õ����λ�����֣��ٽ����жϣ��������������뵽num�ļ����У�Ȼ��
	��x%sumȥ�����λ��sumҲ��Ӧ����10������ѭ��֮����ܵõ�������Ϊ���е����֡�

*/