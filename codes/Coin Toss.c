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
    int t,i;
    double a,b,p,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lf",&n);
        scanf("%lf %lf",&a,&b);
        if(a==0)
        {
            a=1;
        }

        if(b==0)
        {
            b=1;
        }

        a=(a*(1.00/2.00));
        b=(b*(1.00/2.00));

        p=(a+b)/n;
        printf("%lf\n",p);
    }
    return 0;
}
