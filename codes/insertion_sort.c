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
void insertion_sort(int A[],int n)
{
    int i,j,pivot,temp,k;

    for(i=0;i<n;i++)
    {
        pivot=A[i];

        for(j=i-1;j>=0;j--)
        {
            if(pivot<A[j])
            {
                temp=A[j];
                A[j]=pivot;
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
    insertion_sort(A,n);
    return 0;
}
