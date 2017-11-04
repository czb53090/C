# include <stdio.h>
# include <stdlib.h>

int * search(int (* pinter)[4], int n);
int * search2(int (* pinter)[4], int n);

int main(void)
{
	int score[][4] = {{60,70,80,90},{55,66,88,77},{59,78,89,99},{99,98,88,100}};
	int n, i, j;
	int * p;
	printf("input the number of student(1~4):");
	scanf("%d", &n);
	//查找学生成绩
	p = search(score, n-1);

	for (i=0; i<4; i++)
		printf("%5d", *(p+i));
	printf("\n");
	//输出不及格学生的序号和成绩
	for (i=0; i<4; i++)
	{
		p = search2(score, i);
		if (p != NULL)
		{
			printf("No.%d score is:", i+1);
			for (j=0; j<4; j++)	
				printf("%5d", *(p+j));
			printf("\n");
		}
	}

	
	system("pause");
	return 0;
}

int * search(int (* pinter)[4], int n)
{
	int * pt;
	pt = *(pinter+n);
	return pt;
}

int * search2(int (* pinter)[4], int n)
{
	int * pt, i;
	pt = NULL;
	for (i=0; i<4; i++)
		if ((*(*(pinter+n)+i))<60)
			pt = *(pinter+n);
	return pt;
}