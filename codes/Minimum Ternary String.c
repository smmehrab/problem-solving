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
#include<string.h>
int main()
{
    char n[100010],x[100010];
    int i;
    gets(n);

    memset(x, '\0', sizeof(x));

    do{
    strcpy(x, n);

    i=0;
    while(n[i]!='\0')
    {
        if(n[i]=='2' && n[i+1]=='1' )
        {
            n[i]='1';
            n[i+1]='2';
        }
        if(n[i]=='1' && n[i+1]=='0' )
        {
            n[i]='0';
            n[i+1]='1';
        }
        i++;

    }

    }while(strcmp(x, n)!=0);

    printf("%s\n", n);
    return 0;

}
