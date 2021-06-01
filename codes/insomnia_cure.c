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

    int k,l,m,n,d;int c=0;
    scanf("%d",&k);
    scanf("%d",&l);
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&d);

    int s[100001];

    int i;
    if(k>d && l>d && m>d && n>d)
    {
        c=0;
    }
    else if(k==1 || l==1 || m==1 || n==1)
    {
        c=d;
    }
    else{

    for(i=1;i<=d;i++)
    {

        s[i]=1;
    }
    for(i=k;i<=d;i=i+k)
    {

        s[i]=0;
    }
    if(l!=k){
    for(i=l;i<=d;i=i+l)
    {

        s[i]=0;}
    }
    if(m!=l&&m!=k){
    for(i=m;i<=d;i=i+m)
    {

        s[i]=0;
    }}
    if(n!=l&&n!=k&&n!=m){

    for(i=n;i<=d;i=i+n)
    {

        s[i]=0;}
    }

    for(i=1;i<=d;i++)
    {
        if(s[i]==0)
        {c++;}
    }
    }

    printf("%d\n",c);
    return 0;



}
