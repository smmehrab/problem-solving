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
int main()
{
    char s[100000];
    int t,i,j,k,l,c,ans[100000]={0},cs=0,w=0;
    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%s", s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='w' && w==0) w=1;

        }
    }
    return 0;
}