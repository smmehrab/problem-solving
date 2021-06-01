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
    int i=0,sl,tl;

    gets(s);

    while(s[i]!='\0')
    {
        i++;
    }

    sl=i;
    i=0;

    gets(t);
    int c=1;

    while(t[i]!='\0')
    {
        i++;
    }

    tl=i;
    i=0;

    if(sl!=tl)
    {
        printf("NO\n");
    }
    else{
            while(i!=sl)
            {
                if(s[i]!=t[tl-1-i])
                {
                    c=0;
                }
                i++;

            }
            if(c==1)
            {
                printf("YES\n");
            }
            else {printf("NO\n");}

    }
    return 0;


}
