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

    int t=0,u=0,v=0,x=0,y=0;
    int j=0;
    if(s[j]=='h')
    {
        t=j+1;
        j++;
    }
    else{
    while(s[j]!='\0')
    {

        if(s[j]=='h')
        {
            t=j;
            j++;
            break;
        }



        j++;
    }}

    if(s[j]=='e')
    {
        u=j;
        j++;
    }


    else{
    while(s[j]!='\0')
    {


        if(s[j]=='e')
        {
            u=j;
            j++;
            break;
        }

        j++;
    }}
    if(s[j]=='l')
    {
        v=j;
        j++;
    }

    else{
    while(s[j]!='\0')
    {


        if(s[j]=='l')
        {
            v=j;
            j++;
            break;
        }

        j++;
    }}
    if(s[j]=='l')
    {
        x=j;
        j++;
    }
    else{
    while(s[j]!='\0')
    {


        if(s[j]=='l')
        {
            x=j;
            j++;
            break;
        }

        j++;
    }}
    if(s[j]=='o')
    {
       y=j;
       j++;
    }
    else{
    while(s[j]!='\0')
    {


        if(s[j]=='o')
        {
            y=j;
            j++;
            break;
        }

        j++;
    }}
    if(t!=0 && u!=0 && v!=0 && x!=0 && y!=0)
    {printf("YES\n");}

    else {printf("NO\n");}


    return 0;
}
