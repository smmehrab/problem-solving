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
    char s[100],t[100];
    int i=0; int c=0;

    gets(s);gets(t);

    while(s[i]!='\0')
    {
        if(s[i]<'a')
        {
            s[i]=s[i]+32;
        }
        if(t[i]<'a')
        {
            t[i]=t[i]+32;
        }
        if(s[i]>t[i])
        {
            c++;
            break;
        }
        if(s[i]<t[i])
        {
            c--;
            break;
        }
        i++;

    }
    printf("%d\n",c);
    return 0;
}
