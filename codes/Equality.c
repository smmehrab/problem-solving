#include<stdio.h>
#include<string.h>

int main()
{
    int n,k,a[100000]={0},r,l,i;
    char s[100000],t;

    scanf("%d %d %s",&n,&k, s);
    l=strlen(s);
    i=0;
    while(i<l)
    {
        a[s[i]-'A']++;
        i++;
    }
    i=0;
    t='A';
    while(i<k)
    {
        if(i==0) r=a[t-'A'];
        else if(a[t-'A']<r) r=a[t-'A'];
        i++;
        t++;
    }
    r*=k;
    printf("%d\n",r);
    return 0;
}
