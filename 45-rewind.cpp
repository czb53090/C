# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	FILE * fp, *fp1, *fp2;
	char ch;

	if ((fp=fopen("45-file.dat","w+")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}

 	ch = getchar();
 	while (ch != '#')
 	{	
 		fputc(ch, fp);
 		ch = getchar();
 	}

 	rewind(fp);
 	while (!feof(fp))
 	{
		putchar(fgetc(fp));
	}
	putchar(10);
	fclose(fp);

	fp1 = fopen("45-file1.dat","r");
	fp2 = fopen("45-file2.dat","w");
	while (!feof(fp1))
		putchar(getc(fp1));
	putchar(10);
	rewind(fp1);
	while (!feof(fp1))
		putc(fgetc(fp1), fp2);
	fclose(fp1);
	fclose(fp2);

	system("pause");
	return 0;
}