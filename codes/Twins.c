/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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
	for (i=0; i < size; i++) scanf("%d", &arr[i]);
    return *arr;

}

int sumArray(int arr[], int size)
{
    int i,sum=0;
    for(i=0;i<size;i++) sum+=arr[i];
    return (sum/2);
}

int main()
{
	int size,mid,insum=0;
	scanf("%d",&size);
	int arr[size];
	scanArray(arr,size);
	quickSort(arr, 0, size-1);
	mid=sumArray(arr,size);
	int i;
	for(i=size-1;i>=0;i--)
	{
	    insum=insum+arr[i];
	    if(insum>=(mid+1)) break;
	}
	printf("%d\n",(size-i));
	return 0;
}

