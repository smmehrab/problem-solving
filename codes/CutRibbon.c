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
{int t = *a;*a = *b;*b = t;}
int partition (int arr[], int low, int high)
{int pivot = arr[high];int i = (low - 1); int j;
for(j = low; j <= high- 1; j++){if (arr[j] <= pivot){i++;swap(&arr[i], &arr[j]);}}
swap(&arr[i + 1], &arr[high]);return (i + 1);}
void quickSort(int arr[], int low, int high)
{if (low < high){int pi = partition(arr, low, high);quickSort(arr, low, pi - 1);quickSort(arr, pi + 1, high);}}

int main()
{

    int n,a[3];
    scanf("%d %d %d %d",&n,&a[0],&a[1],&a[2]);
    quickSort(a, 0, 2);



}
