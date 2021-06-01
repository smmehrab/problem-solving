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

    int r,b,fashion,survive;

    scanf("%d %d",&r,&b);

    if(r<=b)
    {
        fashion=r;
        survive=(b-r)/2;
    }
    else
    {
        fashion=b;
        survive= (r-b)/2;
    }
    printf("%d %d\n",fashion,survive);
    return 0;


}
