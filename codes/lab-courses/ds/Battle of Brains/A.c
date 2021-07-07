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
    int t,n,a,b,c,d,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
        p=a+b+c+d;
        if(p>(n/2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
