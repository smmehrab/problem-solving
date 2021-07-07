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

int main()
{
    int t,i;
    double p,r,a;
    p=2.0* acos(0.0);
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%lf",&r);
        a=(4*r*r)-(p*r*r);
        printf("Case %d: %.2lf\n",i+1,a);
    }
    return 0;
}
