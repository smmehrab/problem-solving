/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>

int main()
{
    unsigned long long int t,w,n,m,cs=0;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&w);
        if(w%2) printf("Case %llu: Impossible\n",++cs);
        else
        {
            m=1;
            n=w;
            while(n%2==0)
            {
                m*=2;
                n/=2;
            }
            printf("Case %llu: %llu %llu\n",++cs,n,m);
        }
    }
    return 0;
}
