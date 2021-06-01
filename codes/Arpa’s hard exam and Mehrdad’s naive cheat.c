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

int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n!=0)
    {
        n%=4;
        if(n==0) printf("6\n");
        else if(n==3) printf("2\n");
        else if(n==2) printf("4\n");
        else if(n==1) printf("8\n");
    }
    else printf("1\n");
    return 0;
}
