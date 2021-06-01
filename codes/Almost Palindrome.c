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
    char s[900000],one,two,three,four;
    int i,l,r=1,c=0,m;

    scanf("%s", s);
    l=strlen(s);

    m=(l/2);

    one=s[m];
    two=s[m];
    three=s[m];
    four=s[m];

    for(i=0;i<m;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            if(c) {one=s[i];two=s[l-1-i];}
            else {three=s[i];four=s[l-1-i];}
            c++;
            if(c>2) {r=0;break;}
        }
    }

    if(l%2==0)
    {
        if(c==1 && r!=0)r=0;
    }

    else
    {
        if(one!=four && one!=three) r=0;
        if(two!=three && two!=four) r=0;
    }

    if(r) printf("YES\n");
    else printf("NO\n");

    return 0;
}
