
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

	int a[3];

	scanArray(a,3);

	quickSort(a, 0, 2);

	printf("%d\n",(a[2]-a[0]));


	return 0;
}
