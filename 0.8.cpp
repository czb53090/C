# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int x; //ȫ�ֱ���

int main(void)
{
	extern int x; //��ѡ�Ķ�������
	char number[30];

	//�������
 	int i;

	putc(getc(stdin),stderr);//��׼�ļ�ָ���׼����-stdin-���̣���׼���-stdout-��ʾ������׼����-stderr-��ʾ��
	
// 	scanf("%d", &x); //�����������
// 	srand(x);
// 	for (i=0; i<5; i++)
//		printf("%d\n", rand());
	//�Զ���������
// 	srand((unsigned int)time(0));
// 	for (i=0; i<5; i++)
// 		printf("%d\n", rand());


	//strlen
// 	int ct = -1;
// 	scanf("%s", number);
// 	while(*(number+(++ct))!='\0');
// 	printf("strlen(number) = %d\n", ct);
// 	printf("number = %d\n", atoi(number)); //���ַ����е�����ת��Ϊint����
// 	printf("number = %lf\n", atof(number)); //���ַ����е�����ת��Ϊdouble����

	
// 	while (gets_s(number) && number[0]!='\0')
// 	//��������һ��char�Ƿ�Ϊ��\0����Ϊ�˷�ֹ������ʱ��ִ��ѭ���������
// 	{
// 		printf("jj\n");
// 	}
	system("pause");
	return 0;
}