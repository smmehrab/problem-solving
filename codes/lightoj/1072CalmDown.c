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
#define pi 3.14159265358979323846
int main()
{
    int t,cs=0;
    double R,r,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf",&R,&n);
        n=sin(pi/n);
        r=(R*n)/(1+n);
        printf("Case %d: %.9lf\n",++cs,r);
    }
    return 0;
}
