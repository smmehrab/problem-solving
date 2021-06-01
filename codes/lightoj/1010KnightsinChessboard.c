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
    int t,cs=0,m,n,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);

        if(m==1) r=n;

        else if(n==1) r=m;

        else if(m==2 || n==2)
        {
            r=(m*n)/2;

            if(r%4 == 1)      r+=1;
            else if(r%4 == 2) r+=2;
            else if(r%4 == 3) r+=1;
        }

        else if((m*n)%2 == 0) r = (m*n)/2;

        else r = ((m*n)/2)+1;

        printf("Case %d: %d\n",++cs,r);
    }
    return 0;
}

