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


    int a,b,c,r;
    scanf("%d %d %d",&a,&b,&c);

    if((a==1 && b==1) || (c==1 && a==1) || (b==1 && c==1))
    {
        if(a==1&&b==1 && c!=1)
        {
            r=(a+b)*c;
        }
        else if(a!=1 && b==1 && c==1)
        {
            r=a*(b+c);
        }
        else{
        r=a+b+c;}
    }
    else if(a==1)
    {
        r=(a+b)*c;
    }
    else if(b==1)
    {
        if(a>c)
        {
            r=a*(b+c);
        }
        else r=(a+b)*c;
    }
    else if(c==1)
    {
        r=a*(b+c);

    }

    else
    {
        r=a*b*c;
    }

    printf("%d\n",r);

    return 0;


}
