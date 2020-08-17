#include<stdio.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

    int n,m,diff,arr[1010];
    scanf("%d %d",&n,&m);

	scanArray(arr,m);

	quickSort(arr, 0, m-1);




    int i,x;
    for(i=0;i<m-n+1;i++)
    {
        diff=arr[i+n-1]-arr[i];
        if(x<diff && i>0)
        {
            diff=x;
        }
        x=diff;



    }

    printf("%d\n",x);




	return 0;
}







