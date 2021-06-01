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
    int t,n,m,cs=0,ans,pm,dif;
    scanf("%d",&t);
    while(t--){
        ans=0; pm=2;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&m);
            dif=m-pm;
            while(dif/5){
                ans+=dif/5;
                dif%=5;
            }
            if(dif) ans++;
            pm=m;
        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
