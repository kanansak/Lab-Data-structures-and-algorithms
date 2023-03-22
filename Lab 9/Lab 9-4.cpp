#include <stdio.h>
#define MAX 30
int interpolation_search(int a[], int low, int high, int val)
{
	int mid;
	while(low <= high)
	{
		mid=low + (high-low) * ((val - a[low]) / (a[high] - a[low]));
		if(val == a[mid])
			return mid;
		if(val < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int main()
{
	int arry[MAX], i, n, val, pos;
	printf("\n Enter the size of the array : ");
	scanf("%d", &n);
	printf("\n Enter %d elements in the array : \n",n);
	for(i = 0; i<n; i++)
		scanf("%d", &arry[i]);
		printf("\n Enter the key element that has to be search : ");
		scanf("%d", &val);
		pos = interpolation_search(arry, 0, n-1, val);
		if(pos == -1)
			printf("\n %d is not found in the array", val);
		else
			printf("\n %d is found in the array at position arry [%d]", val, pos);
		return 0;
}
