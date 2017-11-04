# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	FILE * fp;
	char str[20], ch;
	int i, flag=1;

	if ((fp=fopen("47-file.dat", "w+")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}

	while (flag == 1)
	{
		printf("please input string:\n");
		gets_s(str);
		fprintf(fp, "%s", str);

		printf("Enter 'n' or 'N' to exit?");
		ch = getchar();
		if (ch=='n' || ch=='N')
			flag = 0;
	}
	
	rewind(fp);

	while (fscanf(fp, "%s", str) != EOF)
	{
		for (i=0; str[i]!='\0'; i++)
			if (str[i]>='a' && str[i]<='z')
				str[i] -= 32;
		printf("%s\n", str);
	}

	fclose(fp);
	system("pause");
	return 0;
}