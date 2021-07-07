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
    char s[100000];
    int i,c=0;

    scanf("%[^\r]", s);

        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='"')
            {
                c++;
                if((c%2)==1) {printf("``");}
                else{printf("''");}

            }
            else
            {
                printf("%c",s[i]);
            }
        }

    return 0;

}
