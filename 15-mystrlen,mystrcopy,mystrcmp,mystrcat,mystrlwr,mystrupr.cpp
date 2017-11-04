/*
	2016年11月19日15:36:17
	目的：制作属于自己的strlen,strcopy,strcmp,strcat,strlwr,strupr
	实验分析：
		strlen函数(String Length)      --  测字符串长度
		strcpy函数(String Copy)        --  字符串赋值
		strcmp函数(String Compare)     --  字符串比较函数
		strcat函数(String Cat)         --  字符串连接函数
		strlwr函数(String Lowercase)   --  字符串转换为小写
		strupr函数(String Upperrcase)  --  字符串转换为大写
*/
# include <stdio.h>
# include <stdlib.h>

int mystrlen(char * str);
void mystrcopy(char * str1, char * str2);
int mystrcmp(char * str1, char * str2);
void mystrcat(char * str1, char * str2);
void mystrlwr(char * str);
void mystrupr(char * str);

int main(void)
{
	char a[40] = "I am a student!";
	char b[20] = "You are a teacher!";
	char c[20];
	int n;

	printf("example:\na: %s\nb: %s\n", a, b);

	printf("\n<mystrlen>\n"); 
	printf("length of a is %d\n", mystrlen(a));
	printf("length of b is %d\n", mystrlen(b));

	printf("\n<mystrcopy(b to a)>\n");
	mystrcopy(c, a); //用c保存a的字符串
	mystrcopy(a, b); //b to a
	printf("a: %s\nb: %s\n", a, b);
	mystrcopy(a, c); //还原a的字符串信息

	printf("\n<mystrcmp>\n"); 
	n = mystrcmp(a, b);
	printf("The result is %d,  ", n);
	if (n > 0)
		printf("a > b\n");
	else if (n < 0)
		printf("a < b\n");
	else
		printf("a = b\n");

	printf("\n<mystrcat>\n");
	mystrcopy(c, a); //用c保存a的字符串
	mystrcat(a, b);
	printf("a: %s\nb: %s\n", a, b);
	mystrcopy(a, c); //还原a的字符串信息

	printf("\n<mystrlwr>\n");
	mystrlwr(a);
	mystrlwr(b);
	printf("a: %s\nb: %s\n", a, b);

	printf("\n<mystrupr>\n");
	mystrupr(a);
	mystrupr(b);
	printf("a: %s\nb: %s\n", a, b);

	system("pause");
	return 0;
}

int mystrlen(char * str)
{
	int i = 0;
	while (*(str+i) != '\0')
		i++;
	return i;
}

void mystrcopy(char * str1, char * str2)
{
	while ((*(str1++)=*(str2++)) != '\0');
}

int mystrcmp(char * str1, char * str2)
{
	int n=0;
	while (*(str1++) != *(str2++))
	{
		n = *(--str1) - *(--str2);
		break;
	}
	return n;
}

void mystrcat(char * str1, char * str2)
{
	while (*(str1++) != '\0');
	str1--;
	while ((*(str1++)=*(str2++)) != '\0');
}

void mystrlwr(char * str)
{
	int i;
	for (i=0; *(str+i)!='\0'; i++)
	{
		if (*(str+i)>='A' && *(str+i)<='Z')
			*(str+i) += 'a'-'A';
	}
}

void mystrupr(char * str)
{
	int i;
	for (i=0; *(str+i)!='\0'; i++)
	{
		if (*(str+i)>='a' && *(str+i)<='z')
			*(str+i) -= 'a'-'A';
	}
}