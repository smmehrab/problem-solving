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
    char s[1000];
    int i=0;
    gets(s);
    if(s[i]>='a')
    {
        s[i]=s[i]-32;
    }
    printf("%s\n",s);
    return 0;
}
