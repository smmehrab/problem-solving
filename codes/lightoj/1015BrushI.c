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
    int t,n,m,i,answer,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%d",&n);
        while(n--)
        {scanf("%d",&m); if(m>=0) answer+=m;}
        printf("Case %d: %d\n",++cs,answer);
    }
    return 0;
}
