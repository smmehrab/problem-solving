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
#include<stdlib.h>
#include<math.h>
int main()
{
    double pi= acos(-1.0),r;
    int t,m,d,cs=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&d);
        r=cbrt((3*m)/(4*pi*d));
        r*=r*4*pi;
        printf("Case %d: %lf\n",++cs,r);
    }
    return 0;
}
