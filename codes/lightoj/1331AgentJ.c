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
    double r1,r2,r3,a1,a2,a3,A1,A2,A3,a,b,c,s,A,ans,cosa;
    int t,cs=0;

    scanf("%d",&t);
    while(t--){

        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        s=(a+b+c)/2.00;
        A=sqrt((s*(s-a)*(s-b)*(s-c)));

        a1=acos((((a*a)+(c*c)-(b*b))/(2.00*a*c)));
        a2=acos((((a*a)+(b*b)-(c*c))/(2.00*a*b)));
        a3=acos((((b*b)+(c*c)-(a*a))/(2.00*b*c)));

        A1=(0.5)*r1*r1*a1;
        A2=(0.5)*r2*r2*a2;
        A3=(0.5)*r3*r3*a3;

        ans=A-(A1+A2+A3);

        printf("Case %d: %0.10lf\n",++cs,ans);
    }
    return 0;
}
