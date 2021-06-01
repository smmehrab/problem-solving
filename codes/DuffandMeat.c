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
    int n,a[100100],p[100100],i,j,c,min;
    scanf("%d\n",&n);
    i=0;c=0;
    while(i<n)
    {
        if(i!=n-1){scanf("%d %d\n",&a[i],&p[i]);}
        else{scanf("%d %d",&a[i],&p[i]);}
        if(i==0){min=p[i];}
        if(p[i]<=min){min=p[i];}
        c+=a[i]*min;
        i++;
    }
    printf("%d\n",c);
    return 0;
}
