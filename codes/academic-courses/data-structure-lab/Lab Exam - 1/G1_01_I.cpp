#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,i,j,k,l;
    char s[10000];
    scanf("%s", s);
    scanf("%d",&b);
    l=strlen(s);
    a=0;
    for(i=0;i<l;i++)
    {
        k=s[i]-'0';
        a*=10;
        a+=k;
        if(a>b) a%=b;
    }
    printf("%d\n",a);
    return 0;
}
