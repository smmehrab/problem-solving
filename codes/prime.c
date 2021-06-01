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

int ifprime(int n)
{
    int i=2,c=1;
    if(n%i==0)
    {
        c=0;
    }
    else
    {
        for(i=3; i<=n/2; i+=2)
        {
            if(n%i==0)
            {
                c=0;
                break;
            }
        }
    }

    return c;
}


int main()
{
    int s,i,j;
    while(scanf("%d",&s)==1)
    {
        j=0;i=2;
        while(j!=s)
        {
            if(ifprime(i)==1)
            {
                if(ifprime(i+2)==1)
                {j++;i+=2;}
                else{i++;}
            }
            else{i++;}
        }
        printf("(%d, %d)\n",i-2,i);
    }
    return 0;
}
