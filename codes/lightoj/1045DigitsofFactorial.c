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
double fact[1000007];
int main()
{
    int t,cs=0,i,n,b;
    long long int d;

    for(i=1;i<=1000000;i++) fact[i]=fact[i-1]+log(i);
    scanf("%d",&t);
    while(t--){
            scanf("%d %d",&n,&b);
            d=((fact[n]/log(b*1.00))+1);
            printf("Case %d: %lld\n",++cs,d);
    }
    return 0;
}
