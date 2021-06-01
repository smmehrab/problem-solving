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
    int t,d,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&d,&n);
        while(d--) n=(n*(n+1))/2;
        printf("%d\n",n);
    }
    return 0;
}
