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

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}

int scanArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++) scanf("%d", &arr[i]);
    return *arr;
}



int main()
{
    int i,k,a[12],j;

    scanf("%d",&k);

    scanArray(a,12);
    quickSort(a, 0, 11);

    if(k==0) {printf("0\n");return 0;}

    i=11;
    j=0;

    while(i>=0)
    {
        j+=a[i];
        if(j>=k) break;
        i--;
    }
    if(i==-1 && j<k) printf("%d\n",i);
    else printf("%d\n",(12-i));
    return 0;
}
