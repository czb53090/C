# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	FILE * fp, * in, * out;
	char filename1[20], filename2[20], ch;
	printf("���������õ��ļ�����\n");
	scanf("%s", filename1);
	if ((fp = fopen(filename1,"w")) == NULL) //������ļ���ʹfpָ����ļ�
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0); //��ֹ����
	}
	ch = getchar(); //���������������Ļس���

	
	printf("������һ��׼���洢�����̵��ַ�������#������ ��");
	ch = getchar(); //���մӼ�������ĵ�һ���ַ�
	while (ch != '#')
	{
		fputc(ch, fp); //������ļ����һ���ַ�
		putchar(ch); //��������ַ���ʾ����Ļ��
		ch = getchar(); //�ڽ��մӼ��������һ���ַ�
	}
	fclose(fp);
	putchar(10); //10����س���


	//�����洴�����ļ�42-file.dat���Ƶ�����һ���ļ���
	printf("����������ļ����ļ�����\n");
	scanf("%s", filename1);
	printf("����������ļ����ļ�����\n");
	scanf("%s", filename2);
	if ((in = fopen(filename1,"r")) == NULL) //�������ļ�
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0); //��ֹ����
	}
	if ((out = fopen(filename2,"w")) == NULL) //������ļ�
	{
		printf("�޷��򿪴��ļ���\n");
		exit(0); //��ֹ����
	} 
	while (!feof(in)) //���Ϊ���������ļ��Ľ�����־
	{
		ch = fgetc(in); //�������ļ�����һ���ַ����ݷ��ڱ���ch��
		fputc(ch, out); //��chд������ļ���
		putchar(ch); //��ch��ʾ����Ļ��
	}
	putchar(10);
	fclose(in);
	fclose(out);

	system("pause");
	return 0;
}