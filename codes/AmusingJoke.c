#include<stdio.h>
#include<string.h>

int main()
{
    char g[110],h[110],f[220];
    gets(g);
    gets(h);
    gets(f);

    int p[26]={0},q[26]={0},i=0,j;

    while(i<strlen(g))
    {
        j=g[i]-'A';
        p[j]++;
        i++;
    }

    i=0;
    while(i<strlen(h))
    {
        j=h[i]-'A';
        p[j]++;
        i++;
    }

    i=0;
    while(i<strlen(f))
    {
        j=f[i]-'A';
        q[j]++;
        i++;
    }

    int c=1;

    for(i=0;i<26;i++)
    {
        if(p[i]!=q[i])
        {
            c=0;
            break;
        }
    }

    if(c) printf("YES\n");
    else printf("NO\n");

    return 0;
}
