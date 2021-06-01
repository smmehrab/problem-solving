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
    while(1){
    int x,i,j;
    scanf("%d",&x);

    i=1;
    while((2*i)<=x)
    {
        i=2*i;
    }

    i=(x%i)+1;

    printf("%d\n",i);}
    return 0;
}
