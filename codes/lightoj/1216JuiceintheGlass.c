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
#include<math.h>
#define PI 3.14159265358979323846

int main()
{
    double r1,r2,h,p,v;
    int t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        if(h!=p) {r1=r2+((r1-r2)/h)*p;h=p;}
        v=(PI*h/3.00)*((r1*r1)+(r1*r2)+(r2*r2));
        printf("Case %d: %.9lf\n",++cs,v);
    }
    return 0;
}
