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
    int easy,hard,t,n,x,y,i,a;
    scanf("%d",&t);
    while(t--)
    {
        easy=0; hard=0;
        scanf("%d %d %d",&n,&x,&y);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(i==0 && a==x) easy=1;
            else if(i==n-1 && a==y) hard=1;
        }
        if(easy&&hard) printf("BOTH\n");
        else if(easy) printf("EASY\n");
        else if(hard) printf("HARD\n");
        else printf("OKAY\n");
    }
    return 0;
}
