# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int num;
	char ch;

//	int status;
//	status = scanf("%d", &num);

// 	while ((scanf("%d", &num)) == 1)
// 	{
// 		printf("num = %d\n", num);
// 	}
	printf("input some char, Crtl+Z to quit!\n");
	ch=getch();
	putchar(ch);
	while((ch=getchar()) != EOF)
		putchar(ch);

	putchar('\a');
// 	printf("enter the number:_______\b\b\b\b\b\b\b");
// 	scanf("%d", &num);
	printf("\tnum = %d", num);
	printf("\rGee!");
	printf("\n");


	system("pause");
	return 0;
}