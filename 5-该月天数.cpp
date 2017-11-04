#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int year,month,day;
	scanf("%d %d", &year, &month);
	switch(month){
		case 1:day=31;break;
		case 2:if(year%4 && year%100 && year%400) day=28;
				else day=29;break;
		case 3:day=31;break;
		case 4:day=30;break;
		case 5:day=31;break;
		case 6:day=30;break;
		case 7:day=31;break;
		case 8:day=31;break;
		case 9:day=30;break;
		case 10:day=31;break;
		case 11:day=30;break;
		case 12:day=31;break;
	}
	printf("%d\n",day);
    system("pause");
	return 0;
}
