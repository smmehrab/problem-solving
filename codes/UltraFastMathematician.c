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

    char s[110],t[110];
    int l;

    gets(s);
    gets(t);

    l=strlen(s);

    char r[l];


    int i=0;

    while(i<l)
    {
        if(s[i]==t[i])
        {
            r[i]='0';
        }
        else
        {
            r[i]='1';
        }
        i++;
    }

    i=0;
    while(i<l)
    {
        printf("%c",r[i]);
        i++;
    }

    printf("\n");
    return 0;
}
