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
    long long int n,ager,porer,i,j,k,max;

    scanf("%lld",&n);
    max=1;
    scanf("%lld",&ager);
    k=1;
    for(i=1;i<n;i++)
    {
        scanf("%lld",&porer);
        if(porer>(2*ager))
        {
            if(k>max) max=k;
            k=1;
        }
        else if(porer!=ager) k++;

        ager=porer;
    }
    if(k>max) max=k;
    printf("%lld\n",max);
    return 0;
}
