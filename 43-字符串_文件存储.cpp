# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
	FILE * fp;
	char filename[10], str[3][10], str2[3][10];
	int i, j, k, n=3;
	char temp[10];


	
	printf("Enter strings:\n");
	for (i=0; i<n; i++)
		gets_s(str[i]);

	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
		{
			 if (strcmp(str[k],str[j])>0)
			 {
				 k = j;
				 strcpy(temp, str[i]);
				 strcpy(str[i], str[k]);
				 strcpy(str[k], temp);
			 }
		}
	}

	printf("input the file name:");
	scanf("%s", filename);
	if ((fp=fopen(filename, "w")) == NULL)
	{
		printf("cannot open the file!\n");
		exit(0);
	}

	printf("\nThe new sequence:\n");
	for (i=0; i<n; i++)
	{
		fputs(str[i], fp);
		fputs("\n", fp);
		printf("%s\n", str[i]);
	}
	fclose(fp);

	if ((fp=fopen(filename, "r")) == NULL)
	{
		printf("cannot open the file!\n");
		exit(0);
	}
	printf("fgets result:\n");
	for (i=0; (fgets(str2[i],10,fp))!=NULL; i++)
	{
		printf("%s", str2[i]);
	}
	fclose(fp);

	system("pause");
	return 0;
}