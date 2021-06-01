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
    int n,h;
    scanf("%d %d",&n,&h);

    int i=0;
    int l[n],w[n],s=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&l[i]);
        if(l[i]>h)
        {
            w[i]=2;
        }
        else{
            w[i]=1;
        }
        s = s + w[i];

    }
    printf("%d\n",s);
    return 0;
}
