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
    char s[100100];
    int n,i,j,k,l,a,d;
    scanf("%d",&n);
    scanf("%s", s);
    a=0;d=0;i=0;
    while(i<n)
    {
        if(s[i]=='A') a++;
        else d++;
        i++;
    }
    if(a>d) printf("Anton\n");
    else if(d>a) printf("Danik\n");
    else printf("Friendship\n");
    return 0;
}
