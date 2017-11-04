# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int x, j, t, num = 0, sum = 1;

	printf("请输入一个数字：");
	scanf("%d", &x);

	t = x;
	while (t > 10)
	{
		t /= 10;
		sum *= 10; //算出10的n-1次 ，位数
	}
	printf("sum = %d\n", sum);

	while (x > 0)
	{
		j = x / sum;

		printf("j = %d  ", j);
		if (j%2 == 1)
		{
			num = num*10 + j;
		}

		x = x % sum;
		sum /= 10;
		
		printf("x = %d   ", x);
		printf("sum = %d\n\n", sum);
	}
	printf("num = %d\n", num);

	system("pause");
	return 0;
}
/*在Vc++6.0中的输出结果是：
--------------------------
请输入一个数字：1234567
sum = 1000000
j = 1  x = 234567   sum = 100000

j = 2  x = 34567   sum = 10000
  
j = 3  x = 4567   sum = 1000
	
j = 4  x = 567   sum = 100
	  
j = 5  x = 67   sum = 10
		
j = 6  x = 7   sum = 1
		  
j = 7  x = 0   sum = 0
			
num = 1357
--------------------------
    总结：输入一个数字x，先算出它的位数n，并定义sum为10的n-1次幂，最循环，直到x<=0，
	每轮循环对x/sum得到最高位的数字，再进行判断，如果是奇数则加入到num的计算中，然后
	让x%sum去掉最高位，sum也相应除以10，依次循环之后就能得到以奇数为排列的数字。

*/