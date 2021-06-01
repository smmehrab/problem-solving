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
void swap(long long int* a, long long int* b)
{long long int t = *a;*a = *b;*b = t;}
long long int partition (long long int arr[],long long  int low,long long int high)
{
	long long int pivot = arr[high];
	long long int i = (low - 1),j;
	for(j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{i++;swap(&arr[i], &arr[j]);}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(long long int arr[],long long  int low,long long int high)
{
	if (low < high)
	{
		long long int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int main()
{
    long long int n,m,a[100100],b[100100],d[100100],i,j,k,l,s;

    scanf("%lld %lld",&n,&m);
    s=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        d[i]=(a[i]-b[i]);
        s+=b[i];
    }
    s=(m-s);
    if(s<0) printf("-1\n");
    else if(s==0) printf("%lld\n",n);
    else{
    quickSort(d, 0, n-1);
    k=0;
    for(i=0;i<n;i++)
    {
        k+=d[i];
        if(k>s){k-=d[i];break;}
    }
    printf("%lld\n",n-i);}
    return 0;
}




