# include <stdio.h>
# include <stdlib.h>
# define N 4
# define M 5 //����Ϊ4��5��

int main(void)
{
	int i, j, k, a[N][M], max, maxj, flag;

	printf("please input matrix:\n");
	for (i=0; i<N; i++) //������ֵ
		for (j=0; j<M; j++)
			scanf("%d", &a[i][j]);

	for (i=0; i<N; i++)
	{
		max = a[i][0];         //��ʼʱ����a[i][0]���
		maxj = 0;              //���к�0����maxj����
		for (j=0; j<M; j++)    //�ҳ���i���е������
			if (a[i][j] > max) 
			{
				max = a[i][j]; //�����е�����������max��
				maxj = j;	   //����������ڵ��кŴ����maxj��
			}
		flag = 1;			   //�ȼ����ǰ��㣬��flagΪ1����
		for (k=0; k<N; k++)
			if (max > a[k][maxj])//�������������ͬ��Ԫ�����
			{
				flag = 0;	   //���max����ͬ����С����ʾ���ǰ��㣬��flagΪ0
				continue;
			}
		if (flag)			   //���flagΪ1��ʾ�ǰ���
		{	
			printf("a[%d][%d] = %d\n", i, maxj, max); //��������ֵ���������к�
			break;
		}
	}
	if (!flag)				   //���flagΪ0��ʾ���㲻����
		printf("It is not exist!\n");

	system("pause");
	return 0;
}