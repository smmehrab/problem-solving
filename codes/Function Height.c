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
    unsigned long long int n,k,r;
    scanf("%llu %llu",&n,&k);
    r=(k/n);
    if(k%n!=0) r++;
    printf("%llu\n",r);
    return 0;
}
