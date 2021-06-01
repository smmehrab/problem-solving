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
    int t,i,j,k,l,s,cs=0;
    long long int a,b,c,d,ba,bb,bc,bd,na,nb,nc,nd;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        scanf("%lld.%lld.%lld.%lld",&ba,&bb,&bc,&bd);
        na=0;
        nb=0;
        nc=0;
        nd=0;
        for(s=0;s<8;s++)
        {
            if(ba%10) na+=pow(2,s);
            if(bb%10) nb+=pow(2,s);
            if(bc%10) nc+=pow(2,s);
            if(bd%10) nd+=pow(2,s);

            ba/=10;
            bb/=10;
            bc/=10;
            bd/=10;
        }
        printf("Case %d: ",++cs);
        if(na!=a || nb!=b || nc!=c || nd!=d) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
