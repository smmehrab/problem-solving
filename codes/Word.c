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
    gets(s);

    int i=0;
    int u=0,l=0;

    while(s[i]!='\0')
    {
        if(s[i]>='a')
        {
            l++;
        }
        else u++;
        i++;
    }

    i=0;

    if(u>l)
    {
        while(s[i]!='\0')
        {
            if(s[i]>='a')
            {
                s[i]=s[i]-32;
            }
            i++;
        }
        i=0;
    }


    else
    {
        while(s[i]!='\0')
        {
            if(s[i]<'a')
            {
                s[i]=s[i]+32;
            }
            i++;
        }
    }

    printf("%s\n",s);
    return 0;

}
