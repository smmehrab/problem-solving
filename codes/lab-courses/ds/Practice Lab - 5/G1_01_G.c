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

int main()
{
	int n,l,i,a[100000];
	double d[100000],dmax;

	scanf("%d %d",&n,&l);

    for (i=0;i<n;i++)
    {scanf("%d",&a[i]);}

	quickSort(a, 0, n-1);
    dmax = a[0];
	for(i=0;i<n-1;i++)
    {
        if(i==n-2 && a[i+1]!=l)
        {
            d[i]=(a[i+1]-a[i])/2.00;
            d[i+1]=(l-a[i+1])*1.00;
            if(d[i]>dmax)
            {dmax=d[i];}
            if(d[i+1]>dmax)
            {dmax=d[i+1];}
        }

        else
        {
            d[i]=(a[i+1]-a[i])/2.00;
            if(d[i]>dmax)
            {dmax=d[i];}
        }
    }
    if(n==1)
    {
        if(dmax<l-a[0]) dmax=l-a[0];
    }
    if(dmax==0) dmax=l;
    printf("%lf\n",dmax);

	return 0;
}
