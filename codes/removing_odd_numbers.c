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

void polynomial_series(int n)
{
    if(n>=0)
    {

        printf(" + x^%d ",n);return polynomial_series(n-1);

    }
}

int main()
{

    int n;
    scanf("%d",&n);

    polynomial_series(n);
    printf("\n");
    return 0;
}
