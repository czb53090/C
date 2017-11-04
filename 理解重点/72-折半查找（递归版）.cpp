# include <stdio.h>
# include <stdlib.h>


int Search(int * elem, int low, int high, int val)
{
    int mid;  
    if(low > high)  
        return -1;  
    else{  
        mid = (low+high) / 2;  
        if(elem[mid] == val)  
            return mid;  
        if(val > elem[mid])  
            return Search(elem, mid+1, high, val);
        else  
            return Search(elem, low, mid-1, val);
    } 
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	
	int position;
	
	if (position=Search(a, 0, 5, 5))
		printf("Is found, position:%d!\n", position+1);
	else
		printf("Not found!\n");
	
	system("pause");
	return 0;
}