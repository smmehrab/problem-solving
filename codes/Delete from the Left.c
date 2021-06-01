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

    char s[999999],t[999999];
    int i,a,b,r;

    gets(s);
    gets(t);

    a=strlen(s)-1;
    b=strlen(t)-1;
    r=0;

    for(i=0;i<=a||i<=b;i++)
    {
        if(r==0)
        {
            if(s[a-i]!=t[b-i] && i<=a && i<=b) r+=2;
            else if(s[a-i]!=t[b-i] && (i>a || i>b)) r++;
        }
        else if(i>a || i>b) r++;
        else r+=2;
    }
    printf("%d\n",r);
    return 0;
}
