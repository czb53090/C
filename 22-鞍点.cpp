/*
	2016��11��14��14:56:00
	Ŀ�ģ�
	����һ��n*n����A������A�İ�����һ��λ�ã�i��j�����ڸ�λ���ϵ�Ԫ���ǵ�i����
	�����������j���ϵ���С����һ������AҲ����û�а��㡣�ҳ�A�İ��㡣 
	���磺
		����������
			4 
			1 7 4 1 
			4 8 3 6 
			1 6 1 2 
			0 7 8 9

		���������
			2 1 
*/
# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int a[100][100] = {0};
	int n, i, j, k, f=-1, w=-2, max, min, cnt=0;
	printf("�������A�İ�����һ��λ�ã�i��j�����ڸ�λ���ϵ�Ԫ���ǵ�i���ϵ����������j���ϵ���С����\n"); 
	printf("�����һ��n*n�ľ���A��n = ");
	scanf("%d", &n);

	//�������
	printf("���������n*n��ÿ��Ԫ�ص�ֵ���Կո�ָ���n��Ϊһ�У���\n");
	for (i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]); 

	//��������
	printf("���������Ϊ���±���0Ϊ��㣩��\n"); 
	for (i=0; i<n; i++)
	{
		max = a[i][0];
		for(j=0; j<n-1; j++)
		{
			if (a[i][j+1] > max)
			{
				max = a[i][j+1];
				k = j+1;
				w = i;
			}
		}

		min = a[0][k];
		for (j=0; j<n-1; j++)
		{
			if (a[j+1][k] < min)
			{
				min = a[j+1][k];
				f = j+1;
			}	
		}
		if (w == f)
		{
			printf("��%d��%d��\n", w, k);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("No found!\n"); 

	system("pause");
	return 0;
}
