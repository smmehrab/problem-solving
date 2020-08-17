
#include<stdio.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); int j;
	for(j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}


int scanArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		scanf("%d", &arr[i]);
    return *arr;

}

int main()
{
	int size,x;
	scanf("%d",&size);

	int arr[size];

	scanArray(arr,size);

	quickSort(arr, 0, size-1);

	x=arr[size-1]-arr[0];

	printf("%d\n",x);
	return 0;
}

