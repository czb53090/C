#include <stdio.h>
#include <stdlib.h>
# include <string.h>
#define x 2    *    8
#define y 2*8

int main(void)
{
	char * a[6] = {
		"Please input the number to chose the funtion you want",
			"1.Search",
			"2.Insert",
			"3.Delete",
			"4.Creat a new Link_list",
			"5.Quit",
	};
	printf("%d\n", strlen(a[0]));
	printf("date is %s\n", __DATE__);
	printf("file is %s\n", __FILE__);
	printf("time is %s\n", __TIME__);
	printf("line is %d\n", __LINE__);
	printf("func is %s\n", __FUNCTION__);
	printf("x=%d, y=%d\n", x, y);

	system("pause");
	return 0;
}