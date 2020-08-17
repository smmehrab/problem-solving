#include<stdio.h>

int main()
{
    long long int t,cs=0,n,c;
    scanf("%lld",&t);
    while(t--)
    {
        c=0;
        scanf("%lld",&n);
        printf("Case %d: ",++cs);
        while(n){
            c++;
            n&=n-1;
        }
        if(c%2==0) printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
