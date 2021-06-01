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
    int t,a[180],i=0;scanf("%d",&t);
    while(i<t){scanf("%d",&a[i]);a[i]=360%(180-a[i]);i++;}i=0;
    while(i<t){if(a[i]== 0){printf("YES\n");}else {printf("NO\n");}i++;}
    return 0;
}
