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

    int n;
    char t;

    scanf("%d",&n);
    scanf("%c",&t);

    int a[n+10],i,j;
    char s[n+10][50];

    for(i=0;i<n;i++) a[i]=0;

    for(i=0;i<n;i++) gets(s[i]);

    for(i=0;i<n;i++)
    {
        int l=strlen(s[i]);
        for(j=0;j<l;j++)
        {
           if(s[i][j]=='A'||s[i][j]=='a'||s[i][j]=='E'||s[i][j]=='e'||s[i][j]=='I'||s[i][j]=='i'||s[i][j]=='u'||s[i][j]=='U'||s[i][j]=='O'||s[i][j]=='o') a[i]+=1;
        }
    }

    int max=a[0];
    for(i=0;i<n;i++)
    {
         if(a[i]>=max) max=a[i];
    }

    for(i=0;i<n;i++)
    {
       if(a[i]==max) printf("%s\n",s[i]);
    }

   return 0;
}
