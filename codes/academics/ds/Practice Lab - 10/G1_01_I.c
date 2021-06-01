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
    char s[20];
    gets(s);
    int c=0,i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='7' || s[i]=='4') c++;
        i++;
    }
    if(c==7 || c==4 || c==44 || c==47|| c==74 || c==77 || c==444 || c==447 || c==474 || c==477 || c==744 || c==747 || c==774|| c==777)
    {
        printf("YES\n");
    }
    else{ printf("NO\n");}

    return 0;
}
