#include<stdio.h>

int main()
{
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    if(a<b) a^=b^=a^=b;
    if(a<c) a^=c^=a^=c;
    if(b<c) c^=b^=c^=b;

    if(d<e) d^=e^=d^=e;
    if(d<f) d^=f^=d^=f;
    if(e<f) e^=f^=e^=f;

    if(a!=d || b!=e || c!=f ) printf("NO\n");
    else if(((b*b)+(c*c))!=(a*a)) printf("NO\n");
    else printf("YES\n");
    return 0;
}
