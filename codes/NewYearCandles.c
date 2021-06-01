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

    int a,b;
    scanf("%d %d",&a,&b);

    int oc=0,roc;
    int x=a;

    while((x/b)!=0 && (b<=a))
    {
        roc=x%b;
        oc=oc+(x/b);
        x=(x/b)+roc;
    }

    a=a+oc;

    printf("%d\n",a);
    return 0;



}
