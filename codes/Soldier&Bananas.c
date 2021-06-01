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
    int k,n,w;
    scanf("%d %d %d",&k,&n,&w);
    int cost=0,neededMoney;
    int i;

    for(i=1;i<=w;i++)
    {
        cost=cost + (i*k);

    }

    neededMoney= cost - n;
    if(neededMoney<0)
    {
        neededMoney=0;
    }
    printf("%d\n",neededMoney);
    return 0;
}
