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

void bubble_sort(int A[],int n)
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;


            }
        }
        for(k=0;k<n;k++)
        {
            printf("%d ",A[k]);
        }
        printf("\n");

    }
}
int main()
{
    int k,n,A[1000];
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        scanf("%d",&A[k]);
    }
    bubble_sort(A,n);
    return 0;
}
