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
    int i,j;
    gets(s);
    i=0;
    while(s[i]!=0)
    {
        if(s[i]<'a') s[i]+=32;
        if(s[i]=='a'|| s[i]=='o' ||s[i]=='y' ||s[i]=='e' ||s[i]=='u' ||s[i]=='i')
        {
            i++;
            continue;
        }
        printf(".%c",s[i]);
        i++;

    }
    return 0;
}
