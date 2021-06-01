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
{while(1){
    int n,k,safe=0,broken=1000,t,maxBroken=0;
    char status[100];
    scanf("%d %d",&n,&k);
    while(n--)
    {
        scanf("%d %s",&t,status);
        if(status[0]=='S' && t>safe) safe=t;
        else if(status[0]=='B')
        {
            if(t<broken) broken=t;
            if(t>maxBroken) maxBroken=t;
        }
    }
    if(safe>maxBroken) printf("%d %d",safe+1,safe);
    else if(safe==0) printf("%d %d",broken,broken-1);
    else printf("%d %d",safe+1,broken-1);
    return 0;
}
