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
    int q,p[200000]={0},g=0,t;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&t);
        p[t]=1;
        if(p[t+1]==1 && p[t-1]==1) g--;
        else if(p[t+1]==0 && p[t-1]==0) g++;
        printf("%d\n",g);
    }
    printf("Justice\n");
    return 0;
}
