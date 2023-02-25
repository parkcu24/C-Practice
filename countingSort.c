#include <stdio.h>
#define MAX_VALUE 100000

void counting_sort(int arr[], int n)
{
	int counting[MAX_VALUE+1] = {0,};
	for (int i=0; i<n; i++)
	{
		counting[arr[i]]++;
	}
	for (int i=1; i<=MAX_VALUE; i++)
	{
		counting[i]+=counting[i-1];
	}

	int result[n];
	for (int i=n-1; i>=0; i--)
	{
		result[counting[arr[i]]-1]=arr[i];
		counting[arr[i]]--;
	}
	

	for(int i=0;i<n;i++){
		arr[i] = result[i];
	}
}


int main()
{
	int arr[] = {4,2,10,8,1,7,6,3,9,5};
	int n = sizeof(arr)/sizeof(int);

	counting_sort(arr,n);

	printf("Sorted array: ");
	for (int i = 0; i <n; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
