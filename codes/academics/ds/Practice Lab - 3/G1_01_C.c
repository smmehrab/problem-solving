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
    char s[1010];
    int i;
    gets(s);
    if(s[0]>='a')
    {
        s[0]=s[0]-32;
    }

    puts(s);
    return 0;
}
