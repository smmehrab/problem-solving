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
    long long int t,cs=0,a,b,i,j,k,l,x,y,as,bs;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);

        i=2*((a-1)/3);
        if((a-1)%3==2) i++;

        j=2*(b/3);
        if(b%3==2) j++;

        printf("Case %lld: %lld\n",++cs,j-i);
    }
    return 0;
}
