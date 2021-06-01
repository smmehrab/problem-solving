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

void reversePrint(int n)
{
    if(n>=0) printf("%d",n);

    if(n==0) printf("\n");
    else if(n>0) printf(" ");

    reversePrint(--n);
}

int main()
{
    int n;
    scanf("%d",&n);
    reversePrint(n);
    return 0;
}
