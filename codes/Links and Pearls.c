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
    char s[110];
    int n,l,i;

    scanf("%s", s);

    n=0;
    l=0;
    i=0;

    while(s[i]!='\0')
    {
        if(s[i]=='o') n++;
        if(s[i]=='-') l++;
        i++;
    }
    if(n==0) printf("YES\n");
    else if(l%n==0) printf("YES\n");
    else printf("NO\n");

    return 0;
}
