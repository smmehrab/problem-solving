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

    int n,k;
    scanf("%d %d",&n,&k);

    k=240-k;
    int i=1,c=0,t=0;
    for(i=1;i<=n;i++)
    {
        t=t+(5*i);
        if(t<=k)
        {
            c++;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",c);
    return 0;
}
