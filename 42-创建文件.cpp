# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	FILE * fp, * in, * out;
	char filename1[20], filename2[20], ch;
	printf("请输入所用的文件名：\n");
	scanf("%s", filename1);
	if ((fp = fopen(filename1,"w")) == NULL) //打开输出文件并使fp指向此文件
	{
		printf("无法打开此文件！\n");
		exit(0); //终止程序
	}
	ch = getchar(); //用来接收最后输入的回车符

	
	printf("请输入一个准备存储到磁盘的字符串（以#结束） ：");
	ch = getchar(); //接收从键盘输入的第一个字符
	while (ch != '#')
	{
		fputc(ch, fp); //向磁盘文件输出一个字符
		putchar(ch); //将输出的字符显示在屏幕上
		ch = getchar(); //在接收从键盘输入的一个字符
	}
	fclose(fp);
	putchar(10); //10代表回车符


	//将上面创建的文件42-file.dat复制到另外一个文件中
	printf("请输入读入文件的文件名：\n");
	scanf("%s", filename1);
	printf("请输入输出文件的文件名：\n");
	scanf("%s", filename2);
	if ((in = fopen(filename1,"r")) == NULL) //打开输入文件
	{
		printf("无法打开此文件！\n");
		exit(0); //终止程序
	}
	if ((out = fopen(filename2,"w")) == NULL) //打开输出文件
	{
		printf("无法打开此文件！\n");
		exit(0); //终止程序
	} 
	while (!feof(in)) //如果为遇到输入文件的结束标志
	{
		ch = fgetc(in); //从输入文件读入一个字符，暂放在变量ch中
		fputc(ch, out); //将ch写到输出文件中
		putchar(ch); //将ch显示在屏幕上
	}
	putchar(10);
	fclose(in);
	fclose(out);

	system("pause");
	return 0;
}