# include <stdio.h>
# include <stdlib.h>
# define N 15

int main(void)
{
	int i, number, top, bott, mid, loca, a[N], flag=1, sign;
	char c;
	printf("enter data:\n");
	scanf("%d", &a[0]); //�����1����
	i = 1;
	while (i<N)
	{
		scanf("%d", &a[i]); //������һ����
		if (a[i] >= a[i-1]) //������������С��ǰһ����
			i++;			//ʹ������ż�1
		else
			printf("enter this data again:\n"); //Ҫ�������������
	}
	printf("\n");
	for (i=0; i<N; i++)
		printf("%5d", a[i]); //���ȫ��15����
	printf("\n");

	while (flag)
	{
		printf("input number to look for:"); //������Ҫ�����ĸ���
		scanf("%d", &number); //����Ҫ���ҵ���
		sign = 0; //signΪ0��ʾ��δ�ҵ�
		top = 0; //top�ǲ����������ʼλ��
		bott = N - 1; //bott�ǲ����������ĩλ��

		if ((number<a[0]) || (number>a[N-1])) //Ҫ���ҵ������ڲ���������
			loca = -1; //��ʾ�Ҳ�������������ж�

		while ((!sign) && (top<=bott))
		{
			mid = (bott+top) / 2;
			if (number == a[mid])
			{
				loca = mid;
				printf("Has found %d, its position is %d.\n", number, loca+1);
				//�����±��0���𣬶�����ϰ�ߴ�1������������λ��Ҫ��1
				sign = 1; //��ʾ�ҵ��ˣ�����ѭ���ı�ʶ
			}
			else if (number < a[mid]) //���Ҫ���ҵ���С���м�Ԫ�ص�ֵ
				bott = mid -1;		  //ֻ����±�Ϊ0~mid-1�ķ�λ����
			else					  //���Ҫ���ҵ�����С���м�Ԫ�ص�ֵ
				top = mid + 1;		  //ֻ����±�Ϊmid+1~bott�ķ�λ����
		}

		if (!sign || loca==-1) // signΪ0 �� loca����-1 ʱ����ζ���Ҳ���
			printf("cannot found %d.\n", number); //����Ҳ���

		printf("continue of not(Y/N)?"); //�����Ƿ��������
		scanf(" %c", &c); //�����������'n'��'N'
		if (c=='n' || c=='N')
			flag = 0; //flag�ǿ��ر��������Ƴ����Ƿ��������
	}

	system("pause");
	return 0;
}