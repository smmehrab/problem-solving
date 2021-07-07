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
#include<string.h>
void swap(int* a, int* b)
{int t = *a;*a = *b;*b = t;}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); int j;
	for(j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot){i++;swap(&arr[i], &arr[j]);}
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

	int s,n,i,x[10100],y[10100],p[10100];

	scanf("%d %d",&s,&n);

    memset(p, -1, 10100*sizeof(p[0]));

	i=0;

	while(i<n)
    {
        if(i==n-1){scanf("%d %d",&x[i],&y[i]);}

        else {scanf("%d %d\n",&x[i],&y[i]);}

        if(p[x[i]]!=-1){p[x[i]]+=y[i];}

        else {p[x[i]]=y[i];}

        i++;
    }

	quickSort(x, 0, n-1);

	i=0;

    while(i<n)
    {
        if(x[i]!=x[i-1] || i==0)
        {
            if(s>x[i]){s=s+p[x[i]];}

            else {s=-1;break;}
        }

        i++;

    }

    if(s==-1){printf("NO\n");}

    else {printf("YES\n");}

	return 0;
}
