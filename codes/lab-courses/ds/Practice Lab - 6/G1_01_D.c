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

int main()
{
    char s[200],t[200],temp;
    int i,j,k,l,sl,tl;
    scanf("%s%c", s,&temp);
    sl=strlen(s);

    k=1;
    i=sl-1;


    while(i>=0)
    {
        scanf("%c",&j);
        if(j!=s[i]) {k=0;break;}
        else if(j=='\0') break;
        else i--;
    }


    if(k==0) printf("NO\n");
    else printf("YES\n");

    return 0;
}
