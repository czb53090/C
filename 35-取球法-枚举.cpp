/*
	2016��11��20��15:27:40
	Ŀ�ģ���5�ֲ�ͬ��ɫ��С�����ɸ�����ȡ��3����ͬ��ɫС���ȡ��
*/

# include <stdio.h>
# include <stdlib.h>

enum Color{red, green, blue, white, black};

int main(void)
{
	int i, j, k, color, pri, n=0;

	for (i=red; i<=black; i++)
		for (j=red; j<=black; j++)
			if (i != j)
				for (k=red; k<=black; k++)
				{
					if (k!=i && k!=j)
					{
						n = n + 1;
						printf("%-4d", n);
						for (color=0; color<3; color++)
						{		
							switch(color)
							{
								case 0: pri = i; break;
								case 1: pri = j; break;
								case 2: pri = k; break;
								default: break;
							}
							switch(pri)
							{
								case red: printf("%-6s", "Red"); break;
								case green: printf("%-6s", "Green"); break;
								case blue: printf("%-6s", "Blue"); break;
								case white: printf("%-6s", "White"); break;
								case black: printf("%-6s", "Black"); break;
								default: break;
							}		
						}
						printf("\n");
					}
				}

	system("pause");
	return 0;
}