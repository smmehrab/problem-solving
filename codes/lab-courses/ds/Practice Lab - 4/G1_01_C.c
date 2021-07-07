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

    char s[100];
    gets(s);
    int i=0,c=0;

    while(s[i]!='\0')
    {
        if(s[i]=='H' ||s[i]=='Q' || s[i]=='9')
        {
            c=1;

        }
        i++;
    }
    if(c==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}
