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
#include<string.h>
char s[2000100],t[2000100];
int main()
{
    long long int n,m,i,r,w;

    scanf("%lld %lld",&n,&m);
    scanf("%s %s", s, t);

    if(n>m+1)
    {
        printf("NO\n"); return 0;
    }

    w=-1;r=1;

    for(i=0;i<n;i++)
    {
        if(s[i]=='*'){w=i;break;}
    }

    if(w==-1)
    {
        if(strcmp(s,t)==0) printf("YES\n");
        else printf("NO\n");
        return 0;
    }

    else
    {
        for(i=0;i<w;i++)
        {
            if(s[i]!=t[i]) {r=0;break;}
        }

        for(i=1;(n-i)>w;i++)
        {
            if(s[n-i]!=t[m-i]) {r=0;break;}
        }
    }

    if(r==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}

