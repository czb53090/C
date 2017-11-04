# include <stdio.h>
# include <stdlib.h>
# define SIZE 10

void save();
void read();

struct Student
{
	char name[10];
	int num;
	int agg;
	char addr[15];
} stu[SIZE],stu2[SIZE];

int main(void)
{
	int i;

	printf("input the Student information(name,num,agg,addr):\n");
	for (i=0; i<SIZE; i++)
		scanf("%s %d %d %s", stu[i].name, &stu[i].num, &stu[i].agg, stu[i].addr);

	save();
	read();

	system("pause");
	return 0;
}

void save()
{
	FILE * fp;
	int i;

	if ((fp=fopen("44-file.dat","wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}
	for (i=0; i<SIZE; i++)
		if(fwrite(&stu[i], sizeof(struct Student), 1, fp) != 1)
			printf("file write error!\n");

	fclose(fp);
}
void read()
{
	FILE * fp;
	int i;

	if ((fp=fopen("44-file.dat","rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(0);
	}
	
	for (i=0; i<SIZE; i++)
	{
		fread(&stu2[i], sizeof(struct Student), 1, fp);
		printf("%-10s%4d%4d%15s\n", stu[i].name, stu[i].num, stu[i].agg, stu[i].addr);
	}	

	fclose(fp);
}