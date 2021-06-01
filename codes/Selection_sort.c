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
void selection_sort(int A[],int n)
{
    int i,j,k,index_min,temp;

    for(i=0;i<=n-1;i++)
    {
        index_min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[index_min])
            {
                index_min=j;

            }
        }

        if(index_min!=i)
        {
            temp=A[index_min];
            A[index_min]=A[i];
            A[i]=temp;
            //printf("%d ",A[i]);


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
    selection_sort(A,n);
    return 0;
}
