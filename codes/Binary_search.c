/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m=l+(r-l)/2;
        if(arr[m] == x) return m;
        else ((arr[m]<x)?(l=m+1):(r=m-1));
    }
    return -1;
}

int main()
{
    int arr[100000],n,i,x,r;
    printf("Enter Number of Elements:\n");
    scanf("%d",&n);
    printf("Enter the Sorted Elements:\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter the Element to Search:\n");
    scanf("%d",&x);
    r = binarySearch(arr, 0, n-1, x);
    (r == -1)? printf("Element is not present in array\n"): printf("Element is present at index %d\n", r);
    return 0;
}
