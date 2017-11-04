# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	char a[3][80];
	int  i, j, upp, low, dig, spa, oth;
	upp = low = dig = spa = oth = 0;

	for (i=0; i<3; i++)
	{
		printf("please input line %d\n", i+1);
		gets_s(a[i]);
		for (j=0; j<80 && a[i][j]!='\0'; j++)
			if (a[i][j]>='A' && a[i][j]<='Z')
				upp++;
			else if(a[i][j]>='a' && a[i][j]<='z')
				low++;
			else if(a[i][j]>='0' && a[i][j]<='9')
				dig++;
			else if(a[i][j] == ' ')
				spa++;
			else
				oth++;
	}

	printf("\nupper case:%d\nlower case:%d\ndigit:%d\nspace:%d\nother:%d\n", upp, low, dig, spa, oth);

	system("pause");
	return 0;
}