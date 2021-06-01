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
    long long int n,odd[100000],s=0,o=0,i,minOdd;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&i);
        if(i%2==0) s+=i;
        else odd[o++]=i;
    }

    if(o%2==0)
    {
        for(i=0;i<o;i++) s+=odd[i];
    }
    else
    {
        for(i=0;i<o;i++)
        {
            s+=odd[i];
            if(i==0) minOdd=odd[i];
            else if(odd[i]<minOdd) minOdd=odd[i];
        }
        s-=minOdd;
    }

    printf("%lld\n",s);

    return 0;
}
