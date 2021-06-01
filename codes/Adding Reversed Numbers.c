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
    int t,a,b,ra,rb,s,rs;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);

        ra=0;
        rb=0;

        while(a)
        {
            ra=(ra*10)+(a%10);
            a/=10;
        }

        while(b)
        {
            rb=(rb*10)+(b%10);
            b/=10;
        }

        s=ra+rb;
        rs=0;

        while(s)
        {
            rs=(rs*10)+(s%10);
            s/=10;
        }

        printf("%d\n",rs);
    }
    return 0;
}
