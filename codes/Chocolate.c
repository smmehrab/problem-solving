#include<stdio.h>
#include<string.h>

int main()
{
    char s[100000];
    int k,n,m,r,c=0,i;
    scanf("%d %d %d",&k,&n,&m);
    for(i=0;i<k;i++)
    {
        scanf("%s", s);
        if(strcmp(s,"Mars")==0) c++;
    }
    c-=n;
    if(c<0) c=0;
    r=(m+n+c)-k;
    if(r<0) r=0;
    printf("%d\n",r);
    return 0;
}
