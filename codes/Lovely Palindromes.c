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
#include<string.h>
char n[10000000];
unsigned long long int x;
int main()
{
    gets(n);
    printf("%s",n); x=strlen(n);
    while(x--) printf("%c",n[x]);
    printf("\n");
    return 0;
}

