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

double max(double a,double b)
{
    if(a>b) return a;
    else return b;
}


int main()
{
    int T,cs=0;
    double v1,v2,v3,a1,a2,t1,t2,d1,d2,t,b,d;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        t1=(v1/a1); t2=(v2/a2);
        t=max(t1,t2);
        b=(v3*t);
        d1=(t1*v1)-(1/2.00)*a1*t1*t1;
        d2=(t2*v2)-(1/2.00)*a2*t2*t2;
        d=d1+d2;
        printf("Case %d: %.8lf %.8lf\n",++cs,d,b);
    }
    return 0;
}
