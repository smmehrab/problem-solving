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
    int n,k,r;
    while(scanf("%d %d",&n,&k)==2 && k>1)
    {
        r=n;
        while(n>=k)
        {
            r=r+(n/k);
            n=(n/k)+(n%k);
        }

        printf("%d\n",r);
    }

    return 0;
}