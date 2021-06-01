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

    int n,i,c,j,a[26];


    char s[10000],T;

    gets(s);

    j=0;

    while(j<26)
    {a[j]=0;j++;}

    j=0;T='A';

    while(j<26)
    {
        i=0;
        while(s[i]!='\0')
        {
            if((s[i]==T)||(s[i]==T+32))
            {a[j]=1;}
            i++;
        }
        T++;j++;
    }

    j=0;c=0;

    while(j<26)
    {
        if(a[j]==1)
        {c++;}
        j++;
    }

    if(c==26)
    {printf("pangram\n");}

    else
    {printf("not pangram\n");}

    return 0;

}
