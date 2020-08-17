#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;
	int larr[n1], rarr[n2];

	for (i = 0; i < n1; i++)
        larr[i] = arr[l + i];
	for (j = 0; j < n2; j++)
        rarr[j] = arr[m + 1+ j];

    i=0; j=0; k=l;

	while (i < n1 && j < n2)
        (larr[i] <= rarr[j]) ? (arr[k++] = larr[i++]) : (arr[k++] = rarr[j++]);

	while (i < n1)
        arr[k++] = larr[i++];
	while (j < n2)
        arr[k++] = rarr[j++];
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}


void printArray(int A[],int size)
{
	int i;
	for (i=0; i < size; i++) printf("%d ",A[i]);
	printf("\n");
}

int scanArray(int A[],int size)
{
	int i;
	for (i=0; i < size; i++) scanf("%d",&A[i]);
    return A;
}


int main()
{
	int n;
	scanf("%d",&n);
	int A[n],i;
    scanArray(A,n);
	mergeSort(A,0,n+1);

	printArray(A,n);

	return 0;
}
