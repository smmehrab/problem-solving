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


int city_to_go(int a[],int i)
{
    while(i!=0)
    {
        if(a[i]<a[i-1])
        {
            int t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
        i--;
    }



        int y=a[1];
        return y;

}
int still_rodzil(int b[],int k)
{
    while(k!=1)
    {
        if(b[k]<b[k-1])
        {
            int t=b[k];
            b[k]=b[k-1];
            b[k-1]=t;
        }
        k--;
    }



        int z=b[2];
        return z;

}
int main()
{
    int n; int e[100000],ee[100000];
    int p,j,x;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&e[j]);
        ee[j]=e[j];


    }
    x = city_to_go(e,n);
    p = still_rodzil(e,n);
    if(x==p) {printf("Still Rozdil\n");}
    else {
            while(x!=ee[j]&&j>0)
            {
                j--;
            }
            printf("%d\n",j);}

    return 0;
}
