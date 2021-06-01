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
    int n,k,x,y,c;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&x);
    scanf("%d",&y);

    if(n<=k)
    {
        c=x*n;

        printf("%d\n",c);
    }
    else
    {
        n=n-k;
        c=x*k;
        c+=y*n;

        printf("%d\n",c);

    }
    return 0;
}
