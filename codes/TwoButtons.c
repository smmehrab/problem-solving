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
    while(1){
    int n,m,c,i,j,t;
    scanf("%d %d",&n,&m);

    if(m==n)
    {
        c=0;
    }
    else if(m<n)
    {
        c=((m/n)+n-m);
    }
    else if((m-n)%n==0)
    {
        if(((m-n)/n)%2==0)
        {
            c=((m-n)/n)+n;
        }
        else
        {
            c=(m-n)/n;
        }
    }
    else
    {
       c=(((m/n)+1)*n)-m;
    }

    printf("%d\n",c);
    }
    return 0;

}
