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

int main()
{
    long long int t,cs=0,n,c;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        scanf("%lld",&n);
        printf("Case %d: ",++cs);
        while(n){
            c++;
            n&=n-1;
        }
        if(c%2==0) printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
