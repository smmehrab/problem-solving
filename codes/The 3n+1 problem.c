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

unsigned long long int max(unsigned long long int a,unsigned long long int b){
    if(a>b)
        return a;
    return b;
}

unsigned long long int min(unsigned long long int a,unsigned long long int b){
    if(a>b)
        return b;
    return a;
}

unsigned long long int algo(unsigned long long int n)
{
    unsigned long long int b=0;
    while(1){
        if(n==1)
            return b+1;
        if((n%2)==1)
            n=(3*n)+1;
        else
            n/=2;
        b++;
    }
}

int main()
{
    unsigned long long int i,j,a,b,m,l;

    while(scanf("%llu %llu",&a,&b)==2){
        m=0;
        i=min(a,b);
        j=max(a,b);

        while(i<=j){
            l=algo(i++);
            if(l>m)
                m=l;
        }

        printf("%llu %llu %llu\n",a,b,m);
    }
    return 0;
}
