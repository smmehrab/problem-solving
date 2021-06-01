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

    char lw[1000];
    int n,j=0;
    scanf("%d\n",&n);
    while(j<n){

    gets(lw);
    int i=0;
    while(lw[i]!='\0')
    {
        i++;
    }

    if(i<=10)
    {
        printf("%s\n",lw);
    }
    else
    {
        printf("%c%d%c\n",lw[0],(i-2),lw[i-1]);

    }
    j++;
    }
    return 0;
}
