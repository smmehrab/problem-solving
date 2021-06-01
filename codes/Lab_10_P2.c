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
    char c;
    scanf("%c",&c);

    int x= (int) c;
    if(x<97)
    {
        x=x+32;
        char y = (char) x;

        printf("%c",y);
    }
    else
    {
        x=x-32;
        char y = (char) x;

        printf("%c",y);
    }
    return 0;
}
