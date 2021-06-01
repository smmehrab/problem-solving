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
    int n,x[1100],y[1100],minus,plus,i,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    minus=0;
    plus=0;

    for(i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
        if(y[i]<x[i]) minus+=x[i]-y[i];
        else plus+=y[i]-x[i];
    }

    if(plus>minus) printf("No\n");
    else printf("Yes\n");

    return 0;

}
