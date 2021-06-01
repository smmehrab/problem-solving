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
    int i,j,k,t,n,r;
    char a[200];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s", a);
        r=1;
        for(i=0;i<(n/2);i++)
        {
            if(a[i]!=a[n-i-1])
            {
                if(a[i]>a[n-i-1])
                {if(a[i]-a[n-i-1]!=2) {r=0;break;}}
                else
                {if(a[n-i-1]-a[i]!=2) {r=0;break;}}
            }
        }
        if(r==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
