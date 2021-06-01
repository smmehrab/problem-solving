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
    int n,m,a[100100],q[100100],i,l,r,mid;
    scanf("%d\n",&n);
    i=0;
    while(i<n)
        {
            if(i==n-1)
            {
                scanf("%d\n",&a[i]);
            }
            else
            {
                scanf("%d ",&a[i]);
            }
            if(i!=0)
            {
                a[i]+=a[i-1];
            }
            i++;
        }

    scanf("%d\n",&m);
    i=0;
    while(i<m)
        {
            if(i==m-1)
            {
                scanf("%d",&q[i]);
            }
            else
            {
                scanf("%d ",&q[i]);
            }
            i++;
        }
    i=0;
    while(i<m)
        {
            l=0;r=n-1;
            while(l<r)
            {
                mid=(l+r)/2;
                if(q[i]<=a[mid])
                    {r=mid;}
                else if(q[i]>a[mid])
                    {l=mid+1;}
                /*else if(q[i]>a[l]&&q[i]<=a[r] && r-l==1)
                    {l=r;}*/
            }
        printf("%d\n",l+1);
        i++;
        }
    return 0;
}
