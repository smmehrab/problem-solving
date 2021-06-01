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
    long long int t,i,a,b,c;
    scanf("%lld",&t);

    i=0;
    while(i<t)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a+b>c && b+c>a && c+a>b)
        {
            if(a==b && b==c) printf("Case %d: Equilateral\n",i+1);
            else if(a==b || b==c || c==a) printf("Case %d: Isosceles\n",i+1);
            else printf("Case %d: Scalene\n",i+1);
        }

        else printf("Case %d: Invalid\n",i+1);

        i++;
    }
    return 0;
}




