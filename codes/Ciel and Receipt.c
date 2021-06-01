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
    int t,i,ans,p,j;
    int a[12]={2048,1024,512,256,128,64,32,16,8,4,2,1};
    scanf("%d",&t);
    while(t--){
        ans=0; i=0;
        scanf("%d",&p);
        while(i<=12 && p){
            ans+=(p/a[i]);
            p%=a[i++];
        }
        printf("%d\n",ans);
    }
    return 0;
}
