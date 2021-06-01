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
    char str[50];

    strcpy(str, "Memset application");
    puts(str);

    memset(str,'h',7);
    puts(str);

    return 0;
}
