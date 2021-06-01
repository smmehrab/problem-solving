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
    gets(s);int c=0;
    while(s[c]!='\0')
    {
        c++;
    }
    int i=0,j=0,t;
    while(j<c)
    {


    while(s[i]!='\0' && i+2<=c)
    {

        if(s[i]>s[i+2])
        {
            t=s[i];
            s[i]=s[i+2];
            s[i+2]=t;
        }

        i=i+2;}
        i=0;
        j++;}

    printf("%s\n",s);
    return 0;


}
