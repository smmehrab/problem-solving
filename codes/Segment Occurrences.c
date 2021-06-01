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
    int n,m,q,l,r,i,j,k,a[1000][1000]={0};
    char s[10000],t[10000];
    scanf("%d %d %d",&n,&m,&q);
    scanf("%s", s);
    scanf("%s", t);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            k=0;
            if(j-i+1>=m)
            {
                for(l=i;l<j-m+1;l++)
                {
                    r=0;
                    while(s[l+r]==t[r] && r<m && l+r<n) r++;
                    if(r==m) {k++;l+=m-1;}
                }
            }
            a[i+1][j+1]=k;
        }
    }
    while(q--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",a[l][r]);
    }
    return 0;
}
