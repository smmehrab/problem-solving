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

int a[100];

int fibonacci(int n)
{
    if(n==1 || n==2) return 1;

    else if(a[n]==0)
    {
        a[n]=fibonacci(n-1)+fibonacci(n-2);
        return a[n];
    }




}


int main()
{
    int x,n;
    scanf("%d",&n);
    x=fibonacci(n);

    printf("%d",x);
    return 0;

}
