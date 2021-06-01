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
    double ab,ac,bc,r,ans;int t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&r);
        r=(1.00/r)+1;
        ans=(1.00*ab/sqrt(r));
        printf("Case %d: %.9lf\n",++cs,ans);
    }
    return 0;
}
