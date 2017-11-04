# include <stdio.h>
# include <stdlib.h>

struct Student
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stu[10];

int main(void)
{
	FILE * fp;
	int i;

	if ((fp=fopen("44-file.dat", "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}

	for (i=0; i<10; i+=2)
	{
		fseek(fp,i*sizeof(struct Student),0);
		fread(&stu[i],sizeof(struct Student),1,fp);
		printf("%-10s%4d%5d%-15s\n",stu[i].name,stu[i].num,stu[i].age,stu[i].addr);
	}




	system("pause");
	return 0;
}
