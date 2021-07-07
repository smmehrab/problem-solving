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
    int i,j,k;
    char s[10000];
    i=0;
    while(1)
    {
        scanf("%c",&s[i]);
        if(s[i]=='\n') {printf("%c",s[i]);break;}
        else if(s[i]==' ') printf("\n");
        else printf("%c",s[i]);
        i++;
    }
    return 0;
}
