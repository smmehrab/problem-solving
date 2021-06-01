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

    int n,x,c,i;
    scanf("%d %d",&n,&x);

    i=1;c=0;
    while(i<=n && i<=x)
    {
        if((x%i)==0 && (x/i)<=n){c++;}
        i++;
    }
    printf("%d\n",c);
    return 0;
}
