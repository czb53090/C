# include <stdio.h>
# include <stdlib.h>
# define N 9

typedef struct tax_st //税率表结构声明
{
	int left;		//区间上限
	int right;		//区间下限
	double tax;		//税率
	double duduct;  //税率扣除数
} TAX_LIST;

void acceptdata(TAX_LIST tax_list[],FILE * fp);
double tax_disp(TAX_LIST tax_list[], double income,FILE * fp); //传入月收入数值进行处理

int main(void)
{
	double result, income;
	FILE * fp;
	
	if ((fp=fopen("48-tax-list.dat","wb+")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}
	TAX_LIST tax_list[N];
	acceptdata(tax_list, fp);

	printf("input your income:");
	scanf("%lf", &income);
	result  = tax_disp(tax_list, income, fp);

	printf("Your final income is: %.2lf", result);

	fclose(fp);

	system("pause");
	return 0;
}

void acceptdata(TAX_LIST tax_list[], FILE * fp)
{
	int i;

	printf("input the data to the file(example:0 500 5 0):\n");
	for (i=0; i<N; i++)
	{
		printf("please enter tax_%d:", i+1);
		scanf("%d %d %lf %lf", &tax_list[i].left, &tax_list[i].right, &tax_list[i].tax,& tax_list[i].duduct);
	}
	if((fwrite(tax_list, sizeof(TAX_LIST), N, fp)) != N)
		printf("file write error!\n");
}

double tax_disp(TAX_LIST tax_list[], double income, FILE * fp)
{
	int i;
	double result;

	for (i=0; i<N; i++)
	{
		fread(tax_list, sizeof(TAX_LIST), 1, fp);
		printf("%d %d %lf %lf\n",tax_list[i].left,tax_list[i].right,tax_list[i].tax,tax_list[i].duduct);
		if (tax_list[i].left<=income && tax_list[i].right>income)
		{
			result = income*tax_list[i].tax/100 - tax_list[i].duduct;
		}
	}

	return result;
}