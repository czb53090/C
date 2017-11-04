# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Person
{
	char name[20];
	int cnt;
}leader[3] = {"Li", 0, "Zhang", 0, "Sun", 0};

int main(void)
{
	int i, j;
	char leader_name[20];

	for (i=0; i<10; i++)
	{
		scanf("%s", leader_name);
		for (j=0; j<3; j++)
		{
			if (strcmp(leader[j].name,leader_name) == 0)
				leader[j].cnt++;
		}
	}

	printf("Li: %d\nZhang: %d\nSun: %d\n", leader[0].cnt, leader[1].cnt, leader[2].cnt);

	system("pause");
	return 0;
}