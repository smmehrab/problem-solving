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
    int t,a,b,c,i,r,j;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(b<=a && b<=c)
        {
            j=b;
            b=a;
            a=j;
        }
        else if(c<=a && c<=b)
        {
            j=c;
            c=a;
            a=j;
        }
        if(c<b)
        {
            j=b;
            b=c;
            c=j;
        }

        printf("Case %d: %d\n",i+1,b);
    }
    return 0;
}
