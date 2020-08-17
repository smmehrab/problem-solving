#include<stdio.h>

int main()
{
    int a[30]={0};
    char s[200];
    int i,j,k,l,n;

    scanf("%d",&n);
    scanf("%s", s);

    i=0;
    while(i<n)
    {
        if(s[i]<'a') s[i]+=32;
        a[s[i]-'a']++;
        i++;
    }
    i=0;
    while(i<26)
    {
        if(a[i]==0)
        {
            printf("NO\n");
            return 0;
        }
        i++;
    }
    printf("YES\n");
    return 0;
}
