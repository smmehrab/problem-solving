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
#include<math.h>
int prime(long long int a[],long long int n)
{

    long long int i,j=0,k,z,m=n;
    a[j]=2;
    j++;
    if(n>10000000) {m=10000000;}
    for(i=3;i<=m;i=i+2)
    {

            int prime=1;
            if(m<10){z=m;}
            else {z=sqrt(i);}
            for(k=3;k<=z;k=k+2)
            {
                if(i%k==0 && i!=k)
                {
                    prime=0; break;}
            }
            if(prime==1)
            {a[j]=i;
            j++;}

    }

    return (j-1);


}

int main()
{
    long long int i,n,c=0,x,a[10000000],k=0,p=0;


    while(p!=450)
    {


    scanf("%lld",&n);
    if(n==0) return 0;


    x=prime(a,n);


    for(i=0;i<=x;i++)
    {
        if((n%a[i])==0 && a[i]>k)
        {
            k=a[i];
            c++;
        }

    }

    if(c==1)
    {
        printf("-1\n");


    }
    else {printf("%lld\n",k);}


    p++;c=0;
    k=0;

    }

    return 0;

}
