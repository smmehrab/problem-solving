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

    char a[110],b[110];
    int i,j;

    gets(a);
    gets(b);

    i=0;
    while(a[i]!='\0')
    {
        if(a[i]<'a') a[i]+=32;
        if(b[i]<'a') b[i]+=32;

        if(a[i]<b[i])
        {
            j=-1;
            break;
        }
        else if(a[i]>b[i])
        {
            j=1;
            break;
        }
        else if(a[i]==b[i])
        {
            j=0;
        }
        i++;
    }
    printf("%d\n",j);
    return 0;
}
