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

    int a,b,i;
    scanf("%d %d",&a,&b);


    for(i=1;;i++)
    {
        a=3*a;
        b=2*b;

        if(a>b)
        {
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}
