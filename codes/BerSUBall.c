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
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

	int n,m,i,a[110],b[110],j,c;
	scanf("%d\n",&n);
	scanArray(a,n);
	quickSort(a, 0, n-1);

	scanf("%d\n",&m);
	scanArray(b,m);
	quickSort(b, 0, m-1);
	c=0;i=0;
	if(n>=m)
    {
        while(i<n)
        {
            j=0;
            while(j<m){if(a[i]==b[j] || a[i]-b[j]==1 || b[j]-a[i]==1){c++;b[j]=-111111;break;}j++;}
            i++;
        }
    }
    else
    {
        while(i<m)
        {
            j=0;
            while(j<n){if(b[i]==a[j] || b[i]-a[j]==1 || a[j]-b[i]==1){c++;a[j]=-111111;break;}j++;}
            i++;
        }
    }
	printf("%d\n",c);

	return 0;
}



