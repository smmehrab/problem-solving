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
    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    if(a==b+c)
    {
        printf("%d=%d+%d\n",a,b,c);
    }
    else if(a==b-c)
    {
        printf("%d=%d-%d\n",a,b,c);
    }
    else if(a==b*c)
    {
        printf("%d=%d*%d\n",a,b,c);
    }
    else if(a==b/c)
    {
        printf("%d=%d/%d\n",a,b,c);
    }
    else if((a+b)==c)
    {
        printf("%d+%d=%d\n",a,b,c);
    }
    else if((a-b)==c)
    {
        printf("%d-%d==%d\n",a,b,c);
    }
    else if((a*b)==c)
    {
        printf("%d*%d=%d\n",a,b,c);
    }
    else if((a/b)==c)
    {
        printf("%d/%d=%d\n",a,b,c);
    }
    return 0;
}
