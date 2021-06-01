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
    int n,i,j=0;
    char s[]="aabb";
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(n>j) printf("%c",s[j]);
        j++;
        if(j>3) j-=4;
    }
    printf("\n");
    return 0;
}
