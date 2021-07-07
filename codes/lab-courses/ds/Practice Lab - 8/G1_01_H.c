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
    int i=1,c=0;
    gets(s);
    while(s[i]!='\0')
    {
        if(s[i]==s[i-1])
        {
            c++;
            if(c==6)
            {
                printf("YES\n");
                return 0;
            }
        }

        else{
            c=0;
        }
        i++;
    }


    printf("NO\n");
    return 0;
}
