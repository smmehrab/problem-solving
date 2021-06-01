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

    int k,r,i;
    scanf("%d %d",&k,&r);

    for(i=1;i<=10;i++)
    {
        if((i*k)%10==0 || (i*k)%10==r)
        {
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}
