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

void remove_odd(int i,int n,int *a)
{
    if(i<n)
    {
        if(a[i]%2==0)
        {
            printf("%d ",a[i]);

        }return remove_odd(i+1,n,a);
    }
}

int main()
{
    int n,a[100],i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    remove_odd(0,n,a);

    printf("\n");
    return 0;
}
