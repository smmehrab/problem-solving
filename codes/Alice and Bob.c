#include<stdio.h>
int main()
{
    long long int n,i,j,m=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&j);
        if(j>m) m=j;
    }
    m-=n;
    if(m%2==0) printf("Bob\n");
    else printf("Alice\n");
    return 0;
}
