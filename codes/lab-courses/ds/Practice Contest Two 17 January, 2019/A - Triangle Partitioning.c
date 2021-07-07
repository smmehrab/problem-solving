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

int main(){
    int t,cs=0;
    double a,b,c,r,d;
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);
        d=sqrt(1.00/(1.00+(1.00/r)))*a;
        printf("Case %d: %lf\n",++cs,d);
    }
    return 0;
}
