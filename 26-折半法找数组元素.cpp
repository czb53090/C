# include <stdio.h>
# include <stdlib.h>
# define N 15

int main(void)
{
	int i, number, top, bott, mid, loca, a[N], flag=1, sign;
	char c;
	printf("enter data:\n");
	scanf("%d", &a[0]); //输入第1个数
	i = 1;
	while (i<N)
	{
		scanf("%d", &a[i]); //输入下一个数
		if (a[i] >= a[i-1]) //如果输入的数不小于前一个数
			i++;			//使数的序号加1
		else
			printf("enter this data again:\n"); //要求重新输入此数
	}
	printf("\n");
	for (i=0; i<N; i++)
		printf("%5d", a[i]); //输出全部15个数
	printf("\n");

	while (flag)
	{
		printf("input number to look for:"); //问你想要查找哪个数
		scanf("%d", &number); //输入要查找的数
		sign = 0; //sign为0表示尚未找到
		top = 0; //top是查找区间的起始位置
		bott = N - 1; //bott是查找区间的最末位置

		if ((number<a[0]) || (number>a[N-1])) //要查找的数不在查找区间内
			loca = -1; //表示找不到，后面会有判断

		while ((!sign) && (top<=bott))
		{
			mid = (bott+top) / 2;
			if (number == a[mid])
			{
				loca = mid;
				printf("Has found %d, its position is %d.\n", number, loca+1);
				//由于下标从0算起，而人们习惯从1算起，因此输出的位置要加1
				sign = 1; //表示找到了，结束循环的标识
			}
			else if (number < a[mid]) //如果要查找的数小于中间元素的值
				bott = mid -1;		  //只须从下表为0~mid-1的方位中找
			else					  //如果要查找的数不小于中间元素的值
				top = mid + 1;		  //只须从下表为mid+1~bott的方位中找
		}

		if (!sign || loca==-1) // sign为0 或 loca等于-1 时，意味着找不到
			printf("cannot found %d.\n", number); //输出找不到

		printf("continue of not(Y/N)?"); //问你是否继续查找
		scanf(" %c", &c); //不想查找输入'n'或'N'
		if (c=='n' || c=='N')
			flag = 0; //flag是开关变量，控制程序是否结束运行
	}

	system("pause");
	return 0;
}