# include <stdio.h>
# include <stdlib.h>

# define MAXSIZE 10
# define INSERT_SORT_SIZE 7

void Swap(int * a, int i, int j); // 交换变量
void Bubble_Sort(int * a, int n); // 1.冒泡排序
void Select_Sort(int * a, int n); // 2.选择排序
void Straight_Insert_Sort(int * a, int n); // 3.直接插入排序
void Sheel_Sort(int * a, int n); // 4.希尔排序
void Heap_Sort(int * a, int n); // 5.堆排序，下标从1开始
void Heap_Adjust(int * a, int k, int n); // 5.堆位置调整
void Merge_Sort_Recursion(int * a, int n); // 6.归并排序-递归版
void Merging_Recursion(int * al, int al_size, int * ar, int ar_size); // 6.实现归并，并把结果存到al里
void Merge_Sort_Iteration(int * a, int n); // 7.归并排序-迭代版
void Quick_Sort(int * a, int low, int high); // 8.快速排序
int Partition(int * a, int low, int high); // 8.快速排序操作
void Quick_Sort_Improve(int * a, int low, int high); // 8+.快速排序-改进版
int Partition_Improve(int * a, int low, int high); // 8+.快速排序操作--改进版

int main(void)
{
	int a[MAXSIZE] = {23, 12, 33, 54, 32, 98, 70, 23, 3, 34};

//	Bubble_Sort(a, MAXSIZE);
//	Select_Sort(a, MAXSIZE);
//	Straight_Insert_Sort(a, MAXSIZE);
//	Sheel_Sort(a, MAXSIZE);
//	Heap_Sort(a, MAXSIZE-1); //下标从1开始
//	Merge_Sort_Recursion(a, MAXSIZE);
	Merge_Sort_Iteration(a, MAXSIZE);
//	Quick_Sort(a, 0, MAXSIZE-1);
//	Quick_Sort_Improve(a, 0, MAXSIZE-1);

	for (int i=0; i<MAXSIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	

	system("pause");
	return 0;
}

// 1.冒泡排序
void Bubble_Sort(int * a, int n)
{
	int i, j, flag;
	
	flag = 1;
	for (i=0; i<n-1 && flag; i++)
		for (j=n-1,flag=0; j>i; j--)
		{
			if (a[j-1] > a[j])
			{
				Swap(a, j-1, j);
				flag = 1;
			}
		}
}
// 2.选择排序
void Select_Sort(int * a, int n)
{
	int i, j, min;

	for (i=0; i<n-1; i++)
	{
		min = i;
		for (j=i+1; j<n; j++)
			if (a[j] < a[min])
				min = j;

		if (min != i)
		{
			Swap(a, min, i);
		}
	}
}
// 3.直接插入排序
void Straight_Insert_Sort(int * a, int n)
{
	int i, j, temp;

	for (i=1; i<n; i++)
		if (a[i-1] > a[i])
		{
			temp = a[i];

			for (j=i-1; j>=0 && a[j]>temp; j--)
				a[j+1] = a[j];

			a[j+1] = temp;
		}
}
// 4.希尔排序
void Sheel_Sort(int * a, int n)
{
	int i, j, temp, gap;

	gap = n;
	do 
	{
		gap = gap/3 + 1;

		for (i=gap; i<n; i++)
			if (a[i-gap] > a[i])
			{
				temp = a[i];

				for (j=i-gap; j>=0 && a[j]>temp; j-=gap)
					a[j+gap] = a[j];
				
				a[j+gap] = temp;
			}
	} while (gap > 1);
}
// 5.堆排序，下标从1开始
void Heap_Sort(int * a, int n)
{
	int i;
	// 构造堆
	for (i=n/2; i>0; i--)
		Heap_Adjust(a, i, n);
	// 堆排序
	for (i=n; i>1; i--)
	{
		Swap(a, 1, i);
		Heap_Adjust(a, 1, i-1);
	}
}
// 5.堆位置调整
void Heap_Adjust(int * a, int k, int n)
{
	int i, temp;

	temp = a[k];

	for (i=k*2; i<=n; i*=2)
	{
		if (a[i] < a[i+1])
			i++;
		
		if (temp > a[i])
			break;
		
		a[k] = a[i];
		k = i;
	}

	a[k] = temp;
}
// 6.归并排序-递归版
void Merge_Sort_Recursion(int * a, int n)
{
	if (n > 1)
	{
		int * al = a;
		int al_size = n/2;
		int ar_size = n - al_size;
		int * ar = a + al_size;
		
		Merge_Sort_Recursion(al, al_size);
		Merge_Sort_Recursion(ar, ar_size);
		
		Merging_Recursion(al, al_size, ar, ar_size);
	}
}
// 6.实现归并，并把结果存到al里
void Merging_Recursion(int * al, int al_size, int * ar, int ar_size)
{
	int i, j, k;
	int temp[MAXSIZE];

	i = j = k = 0;
	while (i<al_size && j<ar_size)
	{
		if (al[i] < ar[j])
			temp[k++] = al[i++];
		else
			temp[k++] = ar[j++];
	}

	while (i < al_size)
		temp[k++] = al[i++];

	while (j < ar_size)
		temp[k++] = ar[j++];

	for (i=0,j=(al_size+ar_size); i<j; i++)
		al[i] = temp[i];
}
// 7.归并排序-迭代版
void Merge_Sort_Iteration(int * a, int n)
{
	int i, j;
	int temp[MAXSIZE];
	int left_min, left_max, right_min, right_max;

	for (i=1; i<n; i*=2) // i为步长
		for (left_min=0; left_min<n-i; left_min=right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;

			if (right_max > n)
				right_max = n;

			j = 0;
			while (left_min<left_max && right_min<right_max)
			{
				if (a[left_min] < a[right_min])
					temp[j++] = a[left_min++];
				else
					temp[j++] = a[right_min++];
			}

			while (left_min < left_max)
				a[--right_min] = a[--left_max];

			while (j > 0)
				a[--right_min] = temp[--j];
		}
}
// 8.快速排序
void Quick_Sort(int * a, int low, int high)
{
	int point;

	if (low < high)
	{
		point  = Partition(a, low, high);
		Quick_Sort(a, low, point-1);
		Quick_Sort(a, point+1, high);
	}
}
// 8.快速排序操作
int Partition(int * a, int low, int high)
{
	int point;

	point = a[low];

	while (low < high)
	{
		while (a[high]>=point && low<high)
			high--;
		a[low] = a[high];

		while (a[low]<=point && low<high)
			low++;
		a[high] = a[low];	
	}

	a[low] = point;
	return low;
}
// 8+.快速排序-改进版
void Quick_Sort_Improve(int * a, int low, int high)
{
	int point;

	if (high-low > INSERT_SORT_SIZE)
	{
		while (low < high) // 优化尾递归操作
		{
			point = Partition_Improve(a, low, high);

			if (point-low < high-point)
			{
				Quick_Sort_Improve(a, low, point-1);
				low = point + 1;
			}
			else
			{
				Quick_Sort_Improve(a, point+1, high);
				high = point - 1;
			}
		}		
	}
	else // 小数组时的排序方法优化
	{
		Straight_Insert_Sort(a+low, high-low+1);
	}
}
// 8+.快速排序操作--改进版
int Partition_Improve(int * a, int low, int high)
{
	int point, mid;
	// 优化基准点的选取
	mid = low + (high-low)/2;
	if (a[low] > a[high])
		Swap(a, low, high);
	if (a[mid] > a[high])
		Swap(a, mid, high);
	if (a[mid] > a[low])
		Swap(a, low, mid);

	point = a[low];

	while (low < high)
	{
		while (a[high]>=point && low<high)
			high--;
		a[low] = a[high];

		while (a[low]<=point && low<high)
			low++;
		a[high] = a[low];
	}
	
	a[low] = point;
	return low;
}

// 交换两个变量的值
void Swap(int * a, int i, int j)
{
	int temp;
	
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


