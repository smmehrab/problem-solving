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

    int n,i,a[110],b[110];
    scanf("%d",&n);

    i=1;

    while(i<=n)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
        i++;
    }

    i=1;
    while(i<=n)
    {
        printf("%d\n",b[i]);
        i++;
    }

    return 0;
}
